#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,                    sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C3_1,     RightDrive,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     LeftDrive,     tmotorTetrix, openLoop)

#include "JoystickDriver.c"

///////////////////////////////
//							 //
// 		Puppet Settings 	 //
//							 //
///////////////////////////////

// JoystickPrecision: The threshold for error on the joysticks.
// This is the tolerance for the joysticks being considered 'idle' by the program
// and therefore the program 'sleeping'. This is also used to determine whether
// the robot is going forward or backwards.
// Lower value = more precise.
#define JoystickPrecision	5

typedef struct {
	int joy1_y1;
	int joy1_y2;
	int joy1_x1;
	int joy1_x2;

	int joy2_y1;
	int joy2_y2;
	int joy2_x1;
	int joy2_x2;
} joystickStateForm;

joystickStateForm joystickState;

typedef struct {
	bool waitingStart;
} systemStateForm;

systemStateForm systemState;

bool stopped = false;

task joystickMonitor() {
	while (true) {
		getJoystickSettings(joystick);

		joystickState.joy1_y1 = joystick.joy1_y1;
		joystickState.joy1_y2 = joystick.joy1_y2;
		joystickState.joy2_x1 = joystick.joy1_x1;
		joystickState.joy2_x2 = joystick.joy1_x2;
	}
}

task updateDisplay() {
	if(systemState.waitingStart) {
		nxtDisplayCenteredTextLine(0,"AutoPuppet");
		nxtDisplayCenteredTextLine(1,"---");
		nxtDisplayCenteredTextLine(2,"Waiting for a");
		nxtDisplayCenteredTextLine(3,"connection from");
		nxtDisplayCenteredTextLine(4,"the Field Control");
		nxtDisplayCenteredTextLine(5,"System. Check that");
		nxtDisplayCenteredTextLine(6,"this is set as the");
		nxtDisplayCenteredTextLine(7,"TeleOp program.");
	}
}

void displayInit() {
	bNxtLCDStatusDisplay = true;
	eraseDisplay();
}

task main() {
	systemState.waitingStart = true;

	displayInit();
	StartTask(updateDisplay);

	waitForStart();
	StartTask(joystickMonitor);

	while(stopped == false) {
		Sleep(1);
	}
}
