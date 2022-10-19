
#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "States.h"

enum {
	  ReadingPressureVal,
	  WaitingPressureVal
}Pressure_sensor_state;

extern void (*Flash_Memory_ptr2Fun)(uint32_t);

// Initialize Pressure Sensor
void Pressure_Sensor_init();
extern uint32_t generate_random(uint32_t,uint32_t,uint32_t);

// Declaring States
extern Define_State(ReadingPressureVal);
extern Define_State(WaitingPressureVal);

#endif /* PRESSURE_SENSOR_H_ */
