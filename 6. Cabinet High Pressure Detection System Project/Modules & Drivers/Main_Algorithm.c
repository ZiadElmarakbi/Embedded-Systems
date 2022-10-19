
// --------------------- MainAlgorithm.c -----------------------//
// Created on: October 13, 2022
// Author: ZIAD ELMARAKBI

#include "Main_Init.h"
#include "States.h"

void setup(){

	//--------------- MCAL Initialization ---------------//
	GPIO_INITIALIZATION();

	//--------------- HAL Initialization ---------------//
	Pressure_Sensor_init();
	Alarm_Indicator_init();
	Alarm_Buzzer_init();
	Flash_Memory_init(flashptr, flashArr, flashSpace);

	//--------------- Block Initialization ---------------//
	Alarm_Manager_init();
}

int main(){

	setup();

	while(1)
	{
		Pressure_Sensor_ptr2Fun();
		Delay(500);
		Alarm_Manager_ptr2Fun();
		Delay(500);
	}
	return 0;
}

// uint32_t generate_random(uint32_t x, uint32_t y, uint32_t count){
//
// 	uint32_t i;
// 	for(i = 0; i < count; i++){
// 		int rand_num = (rand() % (y - x + 1)) + 1;
// 		return rand_num;
// 	}
// 	return 0 ;
// }

