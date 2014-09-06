void onWait() {
	displayInit();
    StartTask(updateDisplay);
}

void onStop() {
}

void onRun() {
	StartTask(joystickMonitor);
}

void switchState(int newState) {
	systemState.waitingStart = false;
	systemState.running = false;
	systemState.stopped = false;

	switch(newState) {
		case STATE_WAIT:
			systemState.waitingStart = true;
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
}