task updateDisplay();
void displayInit();

void onWait() {
	displayInit();
    StartTask(updateDisplay);
}

void onStop() {
	PlaySound(soundException);
	motor[LeftDrive] = 0;
	motor[RightDrive] = 0;
}

void onRun() {
	PlaySound(soundBeepBeep);
}

void switchState(int newState) {
	systemState.wait = false;
	systemState.running = false;
	systemState.stopped = false;

	switch(newState) {
		case STATE_WAIT:
			systemState.wait = true;
			onWait();
		break;
		case STATE_RUN:
			systemState.running = true;
			onRun();
		break;
		case STATE_STOP:
			systemState.stopped = true;
			onStop();
		break;
	}

	StartTask(updateDisplay);
}