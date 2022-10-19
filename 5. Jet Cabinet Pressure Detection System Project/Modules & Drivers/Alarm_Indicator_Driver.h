
#ifndef ALARM_INDICATOR_DRIVER_H_
#define ALARM_INDICATOR_DRIVER_H_

#include "States.h"
#include "TypeDef.h"

enum {
	IndicatorAlarm,
	IndicatorIdle
}Alarm_Indicator_Status;

// Initializing Indicator Alarm
void Alarm_Indicator_init();

// Declaring States
void AlarmIndication_State(Indicator_status LEDstatus);
void AlarmIdle_State(Indicator_status LEDstatus);

// Defined in another file but called in this file
extern void Set_Alarm_Indicator(Indicator_status LEDstatus);

#endif /* ALARM_INDICATOR_DRIVER_H_ */
