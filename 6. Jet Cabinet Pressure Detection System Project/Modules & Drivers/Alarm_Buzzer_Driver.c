
#include "Alarm_Buzzer_Driver.h"

void (*Alarm_Buzzer_ptr2Fun)();

void Alarm_Buzzer_init(){

	Alarm_Buzzer_ptr2Fun = State(BuzzIdle);
 	SET_BIT(GPIOA_ODR,13);
//	 DPRINTF("Initializing Alarm Buzzer...\n");
//	 DPRINTF("...Alarm Buzzer Initialized Successfully !!\n\n");
}

// Defining a function to call the Alarming State
void startAlarmBuzzer(){
	Alarm_Buzzer_ptr2Fun = State(BuzzAlarm);
	Alarm_Buzzer_ptr2Fun();
}

// Defining a function to call the Idle State
void stopAlarmBuzzer(){
	Alarm_Buzzer_ptr2Fun = State(BuzzIdle);
	Alarm_Buzzer_ptr2Fun();
}

Define_State(BuzzAlarm){
	Alarm_Buzzer_status  = BuzzAlarm;
	Set_Alarm_Buzzer(0);
}

Define_State(BuzzIdle){
	Alarm_Buzzer_status  = BuzzIdle;
	Set_Alarm_Buzzer(1);
}
