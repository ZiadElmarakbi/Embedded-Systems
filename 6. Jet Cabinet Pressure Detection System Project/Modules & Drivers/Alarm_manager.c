
#include "Alarm_manager.h"

// Pointer to function to alternate between states
void (*Alarm_Manager_ptr2Fun)();

// Initializing Alarm Manager
void Alarm_Manager_init(){

	Alarm_Manager_ptr2Fun = State(Waiting);
	// DPRINTF("Initializing Alarm Manager...\n");
	// DPRINTF("...Alarm Manager Initialized Successfully !!\n\n");
}

// Defining Monitoring State
Define_State(MonitorPressure){

	Alarm_Manager_State = MonitorPressure;

	if(pval < threshold1){

		stopAlarmBuzzer();
		AlarmIndicatorOFF(Red_Off);
		AlarmIndicatorOFF(Yellow_Off);
		AlarmIndicatorON(Green_On);
		
	}

	else if(pval > threshold2){

		AlarmIndicatorOFF(Green_Off);
		AlarmIndicatorOFF(Yellow_Off);
		startAlarmBuzzer();
		AlarmIndicatorON(Red_On);
	}

	else{

		AlarmIndicatorOFF(Red_Off);
		AlarmIndicatorOFF(Green_Off);
		AlarmIndicatorON(Yellow_On);
		startAlarmBuzzer();
		Delay(7000);
		stopAlarmBuzzer();
	}

	Alarm_Manager_ptr2Fun = State(Waiting);
}

// Defining Waiting State
Define_State(Waiting){

	Alarm_Manager_State = WaitingPressure;

	Alarm_Manager_ptr2Fun = State(MonitorPressure);
	Alarm_Manager_ptr2Fun();
}

