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
	LAST_ACTION = LAST_ACTION + 1;
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
	int power1 = y1 * 0.78;
	int power2 = y2 * 0.78;

	int avgpower = (power1 + power2) / 2;

	motor[LeftDrive] = power1;
	motor[RightDrive] = power2;

	if(y1 > 120 && y2 > 120) {
		if(LAST_ACTION_STATE != STATE_FORWARD) {
			if(LAST_ACTION_STATE == STATE_IDLE) {
				writeDebugStreamLine("	Sleep(%d);",LAST_ACTION * 5);
			}
			if(LAST_ACTION_STATE == STATE_BACKWARD) {
				writeDebugStreamLine("	goBackward(%d, %d);",LAST_ACTION_POWER,LAST_ACTION * 5);
			}
			if(LAST_ACTION_STATE == STATE_OTHER) {
				writeDebugStreamLine("	turn(%d, %d, %d);",OTHER_LEFT,OTHER_RIGHT,LAST_ACTION * 5);
			}
			LAST_ACTION = 1;
			LAST_ACTION_STATE = STATE_FORWARD;
			LAST_ACTION_POWER = avgpower;
		} else {
			LAST_ACTION = LAST_ACTION + 1;
			LAST_ACTION_POWER = avgpower;
		}
	} else if(y1 < -120 && y2 < -120) {
		if(LAST_ACTION_STATE != STATE_BACKWARD) {
			if(LAST_ACTION_STATE == STATE_IDLE) {
				writeDebugStreamLine("	Sleep(%d);",LAST_ACTION * 5);
			}
			if(LAST_ACTION_STATE == STATE_FORWARD) {
				writeDebugStreamLine("	goForward(%d, %d);",LAST_ACTION_POWER,LAST_ACTION * 5);
			}
			if(LAST_ACTION_STATE == STATE_OTHER) {
				writeDebugStreamLine("	turn(%d, %d, %d);",OTHER_LEFT,OTHER_RIGHT,LAST_ACTION * 5);
			}
			LAST_ACTION = 1;
			LAST_ACTION_STATE = STATE_BACKWARD;
			LAST_ACTION_POWER = avgpower;
		} else {
			LAST_ACTION = LAST_ACTION + 1;
			LAST_ACTION_POWER = avgpower;
		}
	} else {
		if(LAST_ACTION_STATE != STATE_OTHER) {
			if(LAST_ACTION_STATE == STATE_BACKWARD) {
				writeDebugStreamLine("	goBackward(%d, %d);",LAST_ACTION_POWER,LAST_ACTION * 5);
			}
			if(LAST_ACTION_STATE == STATE_FORWARD) {
				writeDebugStreamLine("	goForward(%d, %d);",LAST_ACTION_POWER,LAST_ACTION * 5);
			}
			if(LAST_ACTION_STATE == STATE_IDLE) {
				writeDebugStreamLine("	Sleep(%d);",LAST_ACTION * 5);
			}
			LAST_ACTION = 1;
			LAST_ACTION_STATE = STATE_OTHER;
			LAST_ACTION_POWER = avgpower;
		} else {
			OTHER_LEFT = power1;
			OTHER_RIGHT = power2;
			LAST_ACTION = LAST_ACTION + 1;
			LAST_ACTION_POWER = avgpower;
		}
	}
}

void onJoy2PosUpdate(int x1, int y1, int x2, int y2) {

}

void displayInit() {
	bNxtLCDStatusDisplay = true;
	disableDiagnosticsDisplay();
	eraseDisplay();
}