task updateJoysticks() {
	getJoystickSettings(joystick);

	joystickState.joy1_y1 = joystick.joy1_y1;
	joystickState.joy1_y2 = joystick.joy1_y2;
	joystickState.joy2_x1 = joystick.joy1_x1;
	joystickState.joy2_x2 = joystick.joy1_x2;

	if(joystick.joy1_y1 > JoystickPrecision || joystick.joy1_y2 > JoystickPrecision || joystick.joy1_y1 < -JoystickPrecision || joystick.joy1_y2 < -JoystickPrecision) {
		onJoy1PosUpdate(joystick.joy1_x1, joystick.joy1_y1, joystick.joy1_x2, joystick.joy1_y2);
	} else {
		onJoy1PosUpdate(0,0,0,0);
	}
}