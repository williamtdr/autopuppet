#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,                    sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C3_1,     RightDrive,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     LeftDrive,     tmotorTetrix, openLoop)

#include "JoystickDriver.c"
#include "settings.h"
#include "globals.h"
#include "joystick.h"
#include "display.h"
#include "state.h"

task main() {
	switchState(STATE_WAIT);
	waitForStart();
	switchState(STATE_RUN);

	while(systemState.stopped == false) {
		Sleep(1);
	}
}
