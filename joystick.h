task joystickMonitor() {
	while (true) {
		getJoystickSettings(joystick);

		joystickState.joy1_y1 = joystick.joy1_y1;
		joystickState.joy1_y2 = joystick.joy1_y2;
		joystickState.joy2_x1 = joystick.joy1_x1;
		joystickState.joy2_x2 = joystick.joy1_x2;

		Sleep(1);
	}
}