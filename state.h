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
}