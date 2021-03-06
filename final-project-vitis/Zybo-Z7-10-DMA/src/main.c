#include "main.h"

#include "audio/audio.h"
#include "dma/dma.h"
#include "intc/intc.h"
#include "userio/userio.h"
#include "iic/iic.h"

#include "xaxidma.h"
#include "xparameters.h"
#include "xil_exception.h"
#include "xdebug.h"
#include "xiic.h"
#include "xaxidma.h"
#include "xtime_l.h"
#include "xscugic.h"
#include "sleep.h"
#include "xil_cache.h"

#define AUDIO_SAMPLE_RATE	96000
#define MAX_REC_TIME_SEC	3
#define AUDIO_SAMPLES		(AUDIO_SAMPLE_RATE * MAX_REC_TIME_SEC)
#define FILE_SIZE			(AUDIO_SAMPLES * 5)

#define AUDIO_SAMPLE_0		(MEM_BASE_ADDR + FILE_SIZE)
#define AUDIO_SAMPLE_1		(MEM_BASE_ADDR + 2*FILE_SIZE)
#define AUDIO_SAMPLE_2		(MEM_BASE_ADDR + 3*FILE_SIZE)
#define AUDIO_SAMPLE_3		(MEM_BASE_ADDR + 4*FILE_SIZE)

static XIic sIic;
static XAxiDma sAxiDma;
static XGpio sUserIO;
static XScuGic sIntc;
const ivt_t ivt[] = {
	//IIC
	{XPAR_FABRIC_AXI_IIC_0_IIC2INTC_IRPT_INTR, (Xil_ExceptionHandler)XIic_InterruptHandler, &sIic},
	//DMA Stream to MemoryMap Interrupt handler
	{XPAR_FABRIC_AXI_DMA_0_S2MM_INTROUT_INTR, (Xil_ExceptionHandler)fnS2MMInterruptHandler, &sAxiDma},
	//DMA MemoryMap to Stream Interrupt handler
	{XPAR_FABRIC_AXI_DMA_0_MM2S_INTROUT_INTR, (Xil_ExceptionHandler)fnMM2SInterruptHandler, &sAxiDma},
	//User I/O (buttons, switches, LEDs)
	{XPAR_FABRIC_AXI_GPIO_0_IP2INTC_IRPT_INTR, (Xil_ExceptionHandler)fnUserIOIsr, &sUserIO}
};
sAudioMixer_t AudioMixer;



int main(void) {
	AudioMixerInit();
	AudioMixerStart();
}

void AudioMixerStart() {
	while(1) {

		// Checking the DMA S2MM event flag
		if (AudioMixer.fDmaS2MMEvent)
		{
			AudioMixerStopRecording();
		}

		// Checking the DMA MM2S event flag
		if (AudioMixer.fDmaMM2SEvent)
		{
			AudioMixerStopPlayback();
			AudioMixerStartPlayback();
		}

		// Checking the btn change event
		if(AudioMixer.fUserIOEvent) {

			switch(AudioMixer.chBtn) {
				case 'r':
				case 'u':
					if (!AudioMixer.fAudioRecord && !AudioMixer.fAudioPlayback)
					{
						AudioMixerStartRecording();
					}
					else
					{
						char *currentOperation = AudioMixer.fAudioRecord ? "Recording" : "Playing back";
						xil_printf("Still %s\r\n", currentOperation);
					}
					break;
				case 'l':
				case 'd':
					if (!AudioMixer.fAudioRecord && !AudioMixer.fAudioPlayback)
					{
						AudioMixerStartPlayback();
					}
					else
					{
						u32 timeLeft = Xil_In32(I2S_PERIOD_COUNT_REG);
						char *currentOperation = AudioMixer.fAudioRecord ? "Recording" : "Playing back";
						xil_printf("Still %s %d\r\n", currentOperation, timeLeft);
					}
					break;
				default:
					break;
			}

			// Reset the user I/O flag
			AudioMixer.chBtn = 0;
			AudioMixer.fUserIOEvent = 0;
		}
	}
}

void AudioMixerStartRecording() {
	xil_printf("\r\nStart Recording...\r\n");
	fnSetMicInput();

	fnAudioRecord(sAxiDma,AUDIO_SAMPLES);
	AudioMixer.fAudioRecord = 1;
}

void AudioMixerStopRecording() {
	xil_printf("\r\nRecording Done...");

	// Disable Stream function to send data (S2MM)
	Xil_Out32(I2S_STREAM_CONTROL_REG, 0x00000000);
	Xil_Out32(I2S_TRANSFER_CONTROL_REG, 0x00000000);

	Xil_DCacheInvalidateRange((u32) MEM_BASE_ADDR, 5*AUDIO_SAMPLES);
	//microblaze_invalidate_dcache();
	// Reset S2MM event and record flag
	AudioMixer.fDmaS2MMEvent = 0;
	AudioMixer.fAudioRecord = 0;
}

void AudioMixerStartPlayback() {
	xil_printf("\r\nStart Playback...\r\n");
	fnSetHpOutput();
	fnAudioPlay(sAxiDma,AUDIO_SAMPLES);
	AudioMixer.fAudioPlayback = 1;
}

void AudioMixerStopPlayback() {
	xil_printf("\r\nPlayback Done...");

	// Disable Stream function to send data (S2MM)
	Xil_Out32(I2S_STREAM_CONTROL_REG, 0x00000000);
	Xil_Out32(I2S_TRANSFER_CONTROL_REG, 0x00000000);
	//Flush cache
//					//microblaze_flush_dcache();
	Xil_DCacheFlushRange((u32) MEM_BASE_ADDR, 5*AUDIO_SAMPLES);
	//Reset MM2S event and playback flag
	AudioMixer.fDmaMM2SEvent = 0;
	AudioMixer.fAudioPlayback = 0;
}

void AudioMixerInit() {
	xil_printf("Initializing AudioMixer\r\n");

	AudioMixer.u8Verbose = 0;
	fnInitInterruptController(&sIntc);
	fnInitIic(&sIic);
	fnInitUserIO(&sUserIO);
	fnConfigDma(&sAxiDma);
	fnInitAudio();
	{
		XTime  tStart, tEnd;

		XTime_GetTime(&tStart);
		do {
			XTime_GetTime(&tEnd);
		}
		while((tEnd-tStart)/(COUNTS_PER_SECOND/10) < 20);
	}
	fnInitAudio();
	fnEnableInterrupts(&sIntc, &ivt[0], sizeof(ivt)/sizeof(ivt[0]));

	xil_printf("Successfully initialized AudioMixer\r\n");
}
