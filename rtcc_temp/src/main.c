#include "main.h"
#include "xtime_l.h"

#define DATE_ROW 0
#define TIME_ROW 1
#define TMP_ROW 2

PmodOLED oled;
PmodRTCC rtcc;
PmodTMP3 tmp;

int main() {
	ProjectInit();
	ProjectRun();
	return 0;
}

void ProjectRun() {
	RTCC_Time time;
	double temp;

	while(1) {
		time = GetTime(rtcc, RTCC_TARGET_RTCC);
		UpdateOledDate(time);
		UpdateOledTime(time);
		temp = GetTemp();
		UpdateOledTmp(temp);
	}
}

void UpdateOledDate(RTCC_Time time) {
	char date_str[9];
	date_str[8] = 0;
	sprintf(date_str, "%2x/%02x/%02x", time.month, time.date, time.year);
	OLED_SetCursor(&oled, 5, DATE_ROW);
	OLED_PutString(&oled, date_str);
}
void UpdateOledTime(RTCC_Time time) {
	char time_str[12];
	time_str[11] = 0;

	sprintf(time_str, "%2x:%02x:%02x %2s", time.hour, time.minute, time.second, (time.ampm == RTCC_AM) ? "AM" : "PM");
	OLED_SetCursor(&oled, 5, TIME_ROW);
	OLED_PutString(&oled, time_str);
}
void UpdateOledTmp(double temp) {
	char temp_str[7];
	sprintf(temp_str, "%4.1f F", temp);
	OLED_SetCursor(&oled, 5, TMP_ROW);
	OLED_PutString(&oled, temp_str);
}


RTCC_Time GetTime(PmodRTCC rtcc, RTCC_Target src) {
	   RTCC_Time val;

	   if (src != RTCC_TARGET_PWRD && src != RTCC_TARGET_PWRU) {
	      val.second = RTCC_getSec(&rtcc, src);
	   }

	   val.minute = RTCC_getMin(&rtcc, src);
	   val.hour   = RTCC_getHour(&rtcc, src);
	   val.ampm   = RTCC_getAmPm(&rtcc, src);
	   val.day    = RTCC_getDay(&rtcc, src);
	   val.date   = RTCC_getDate(&rtcc, src);
	   val.month  = RTCC_getMonth(&rtcc, src);

	   if (src == RTCC_TARGET_RTCC) {
	      val.year = RTCC_getYear(&rtcc);
	   } else {
	      val.year = 0;
	   }

	   return val;
}

double GetTemp() {
	double temp;
	temp = TMP3_getTemp(&tmp);
	return TMP3_CtoF(temp);
}

void ProjectInit() {
	RTCC_Time start_time;

	OLED_Begin(&oled, XPAR_PMODOLED_0_AXI_LITE_GPIO_BASEADDR,
	       XPAR_PMODOLED_0_AXI_LITE_SPI_BASEADDR, 0, 0);
    OLED_SetCursor(&oled, 0, DATE_ROW);
    OLED_PutString(&oled, "DATE");
    OLED_SetCursor(&oled, 0, TIME_ROW);
    OLED_PutString(&oled, "TIME");
    OLED_SetCursor(&oled, 0, TMP_ROW);
    OLED_PutString(&oled, "TMP ");

	RTCC_begin(&rtcc, XPAR_PMODRTCC_0_AXI_LITE_IIC_BASEADDR, 0x6F);
    RTCC_stopClock(&rtcc);
    start_time.hour   = 0x03;
    start_time.minute = 0x05;
    start_time.second = 0x00;
    start_time.ampm   = RTCC_PM;
    start_time.day    = 0x01;
    start_time.month  = 0x12;
    start_time.date   = 0x18;
    start_time.year   = 0x21;
    start_time = IncrementTime(start_time, 0);
    SetTime(rtcc, start_time, RTCC_TARGET_RTCC);
    RTCC_startClock(&rtcc);
    RTCC_enableVbat(&rtcc);

    TMP3_begin(&tmp, XPAR_PMODTMP3_0_AXI_LITE_IIC_BASEADDR, TMP3_ADDR);
}

void SetTime(PmodRTCC rtcc, RTCC_Time val, RTCC_Target dest) {
	   if (dest != RTCC_TARGET_PWRD && dest != RTCC_TARGET_PWRU) {
	      RTCC_setSec(&rtcc, dest, val.second);
	   }

	   RTCC_setMin(&rtcc, dest, val.minute);
	   RTCC_setHour12(&rtcc, dest, val.hour, val.ampm);
	   RTCC_setDay(&rtcc, dest, val.day);
	   RTCC_setDate(&rtcc, dest, val.date);
	   RTCC_setMonth(&rtcc, dest, val.month);

	   if (dest == RTCC_TARGET_RTCC) {
	      RTCC_setYear(&rtcc, val.year);
	   }
}

u8 bcd2int(u8 data) {
   return ((data >> 4) * 10) + (data & 0xF);
}

u8 int2bcd(u8 data) {
   return (((data / 10) & 0xF) << 4) + ((data % 10) & 0xF);
}

RTCC_Time IncrementTime(RTCC_Time time, int delta_seconds) {
   RTCC_Time result;
   int temp;
   result = time;
   temp = bcd2int(result.second) + delta_seconds;
   result.second = int2bcd(temp % 60);          // Convert seconds
   temp = bcd2int(result.minute) + temp / 60;   // Carry seconds -> minutes
   result.minute = int2bcd(temp % 60);          // Convert minutes
   temp = bcd2int(result.hour) + temp / 60 - 1; // Carry minutes -> hours
   result.hour = int2bcd((temp % 12) + 1);      // Convert hours
   return result;
}

