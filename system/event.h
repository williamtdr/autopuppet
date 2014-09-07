task updateDisplay();
task updateJoysticks();

void onSecondPass() {
	switch(TIME_PASSED) {
		case 10:
			PlaySound(soundShortBlip);
		break;
		case 20:
			PlaySound(soundShortBlip);
		break;

		case 25:
			PlaySound(soundShortBlip);
		break;
		case 26:
			PlaySound(soundShortBlip);
		break;
		case 27:
			PlaySound(soundShortBlip);
		break;
		case 28:
			PlaySound(soundShortBlip);
		break;
		case 29:
			PlaySound(soundShortBlip);
		break;
	}

	if(TIME_PASSED == 30) {
		switchState(STATE_STOP);
	}
}

task onTick() {
	TICK_HUNDREDS = TICK_HUNDREDS + 1;
	if(TICK_HUNDREDS == 100) {
		TICK_HUNDREDS = 1;

		TIME_PASSED = TIME_PASSED + 1;
		onSecondPass();
	}

	StartTask(updateDisplay);
	if(systemState.running) {
		StartTask(updateJoysticks);
	}
}

void onJoy1PosUpdate(int x1, int y1, int x2, int y2) {
	motor[LeftDrive] = y1 * 0.78;
	motor[RightDrive] = y2 * 0.78;
}

void onJoy2PosUpdate(int x1, int y1, int x2, int y2) {

}

void displayInit() {
	bNxtLCDStatusDisplay = true;
	disableDiagnosticsDisplay();
	eraseDisplay();
}