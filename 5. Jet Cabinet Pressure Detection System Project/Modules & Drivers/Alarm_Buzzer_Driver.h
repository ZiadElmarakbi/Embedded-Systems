
#ifndef ALARM_BUZZER_DRIVER_H_
#define ALARM_BUZZER_DRIVER_H_

#include "States.h"

enum{
	BuzzAlarm,
	BuzzIdle
}Alarm_Buzzer_status;

// Initializing Buzzer Alarm
void Alarm_Buzzer_init();

void stopAlarmBuzzer();
void startAlarmBuzzer();

// Declaring States
extern Define_State(BuzzAlarm);
extern Define_State(BuzzIdle);

#endif /* ALARM_BUZZER_DRIVER_H_ */
