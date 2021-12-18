#include "xparameters.h"
#include "xil_printf.h"
#include "PmodOLED.h"
#include "PmodRTCC.h"
#include "PmodTMP3.h"
#include "sleep.h"
#include <stdio.h>

void ProjectInit();
void ProjectRun();
void ProjectCleanup();

typedef struct RTCC_Time {
   u8 second;
   u8 minute;
   u8 hour;
   u8 ampm;
   u8 day;
   u8 date;
   u8 month;
   u8 year;
} RTCC_Time;

RTCC_Time GetTime(PmodRTCC rtcc, RTCC_Target src);
void SetTime(PmodRTCC rtcc, RTCC_Time val, RTCC_Target dest);
RTCC_Time IncrementTime(RTCC_Time time, int delta_seconds);

double GetTemp();

void UpdateOledDate(RTCC_Time time);
void UpdateOledTime(RTCC_Time time);
void UpdateOledTmp(double temp);
