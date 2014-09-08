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
#include "system/globals.h"
#include "config/settings.h"
#include "system/strings.h"
#include "system/state.h"
#include "system/event.h"
#include "system/doTick.h"
#include "task/UpdateDisplayTask.h"
#include "task/UpdateJoystickTask.h"

task main() {
	bMotorReflected[LeftDrive] = true;

	switchState(STATE_WAIT);

	waitForStart();

	StartTask(tick);
	switchState(STATE_RUN);
	while(systemState.stopped == false) {
		Sleep(1000);
	}

	Sleep(30000);  // give the user a chance to see the message
}
