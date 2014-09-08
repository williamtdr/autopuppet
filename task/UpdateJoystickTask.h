task updateJoysticks() {
	getJoystickSettings(joystick);

	joystickState.joy1_y1 = joystick.joy1_y1;
	joystickState.joy1_y2 = joystick.joy1_y2;
	joystickState.joy2_x1 = joystick.joy1_x1;
	joystickState.joy2_x2 = joystick.joy1_x2;

	if(joystick.joy1_y1 > JoystickPrecision || joystick.joy1_y2 > JoystickPrecision || joystick.joy1_y1 < -JoystickPrecision || joystick.joy1_y2 < -JoystickPrecision) {
		onJoy1PosUpdate(joystick.joy1_x1, joystick.joy1_y1, joystick.joy1_x2, joystick.joy1_y2);
	} else {
		motor[LeftDrive] = 0;
		motor[RightDrive] = 0;
		if(LAST_ACTION_STATE != STATE_IDLE) {
			if(LAST_ACTION_STATE == STATE_FORWARD) {
				writeDebugStreamLine("	goForward(%d, %d);",LAST_ACTION_POWER,LAST_ACTION * 5);
			}
			if(LAST_ACTION_STATE == STATE_BACKWARD) {
				writeDebugStreamLine("	goBackward(%d, %d);",LAST_ACTION_POWER,LAST_ACTION * 5);
			}
			if(LAST_ACTION_STATE == STATE_OTHER) {
				writeDebugStreamLine("	turn(%d, %d, %d);",OTHER_LEFT,OTHER_RIGHT,LAST_ACTION * 10);
			}
			LAST_ACTION = 1;
			LAST_ACTION_STATE = STATE_IDLE;
		} else {
			LAST_ACTION = LAST_ACTION + 1;
		}
	}
}