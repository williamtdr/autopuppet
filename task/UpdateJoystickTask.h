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
            writePrevLine();
            LAST_ACTION_STATE = STATE_IDLE;
        }

		LAST_ACTION = LAST_ACTION + 1;
	}
}