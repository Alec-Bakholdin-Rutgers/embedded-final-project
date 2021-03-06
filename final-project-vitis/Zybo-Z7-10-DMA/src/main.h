#ifndef MAIN_H_2
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xil_io.h"
#include "xstatus.h"
#include "xparameters.h"
#include "xil_cache.h"

#define RETURN_ON_FAILURE(x) if ((x) != XST_SUCCESS) return XST_FAILURE;

#define DMA_DEV_ID			XPAR_AXIDMA_0_DEVICE_ID

#define DDR_BASE_ADDR       XPAR_PS7_DDR_0_S_AXI_BASEADDR
#define MEM_BASE_ADDR		(DDR_BASE_ADDR + 0x10000000)

#define RX_INTR_ID			XPAR_FABRIC_AXI_DMA_0_S2MM_INTROUT_INTR
#define TX_INTR_ID			XPAR_FABRIC_AXI_DMA_0_MM2S_INTROUT_INTR

#define TX_BUFFER_BASE		(MEM_BASE_ADDR + 0x00100000)
#define RX_BUFFER_BASE		(MEM_BASE_ADDR + 0x00300000)
#define RX_BUFFER_HIGH		(MEM_BASE_ADDR + 0x004FFFFF)

#define INTC				XScuGic
#define INTC_HANDLER		XScuGic_InterruptHandler


typedef struct {
	u8 u8Verbose;
	u8 fUserIOEvent;
	u8 fVideoEvent;
	u8 fAudioRecord;
	u8 fAudioPlayback;
	u8 fDmaError;
	u8 fDmaS2MMEvent;
	u8 fDmaMM2SEvent;
	int fDVIClockLock;
	char chBtn;
	u8 fLinkEvent;
	u8 fLinkStatus;
	int linkSpeed;
	int mac;
	XStatus fMacStatus;
} sAudioMixer_t;

extern sAudioMixer_t AudioMixer;

void AudioMixerInit();
void AudioMixerStart();

void AudioMixerStartRecording();
void AudioMixerStopRecording();
void AudioMixerStartPlayback();
void AudioMixerStopPlayback();

#endif
