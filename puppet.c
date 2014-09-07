#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C2_1,      ,             tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,      ,             tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     RightDrive,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     LeftDrive,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,      ,             tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,      ,             tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"
#include "settings.h"
#include "globals.h"
#include "joystick.h"
#include "display.h"
#include "state.h"
#include "timer.h"

task main() {
	switchState(STATE_WAIT);
	waitForStart();
	switchState(STATE_RUN);

	while(true) {
		Sleep(100);
	}
}
