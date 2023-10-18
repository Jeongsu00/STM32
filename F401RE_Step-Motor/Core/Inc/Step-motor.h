/*
 * Step-motor.h
 *
 *  Created on: Oct 18, 2023
 *      Author: user
 */

#ifndef INC_STEP_MOTOR_H_
#define INC_STEP_MOTOR_H_

#include "main.h"

#define stepperr1rev 		4096

void stepper_set_rpm ();
void stepper_half_driver();

#endif /* INC_STEP_MOTOR_H_ */
