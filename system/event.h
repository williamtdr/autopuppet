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

void writePrevLine() {
    if(LAST_ACTION > 2) {
        if(LAST_ACTION_STATE == STATE_FORWARD) {
            writeDebugStreamLine("	goForward(%d, %d);",((power_data[2] + power_data[3]) / 2),LAST_ACTION * 5);
        } else if(LAST_ACTION_STATE == STATE_BACKWARD) {
            writeDebugStreamLine("	goBackward(%d, %d);", ((power_data[2] + power_data[3]) / 2), LAST_ACTION * 5);
        } else if(LAST_ACTION_STATE == STATE_LEFT) {
            writeDebugStreamLine("	turnLeft(%d, %d);", ((power_data[2] + power_data[3]) / 2), LAST_ACTION * 2000);
        } else if(LAST_ACTION_STATE == STATE_RIGHT) {
            writeDebugStreamLine("	turnRight(%d, %d);", ((power_data[2] + power_data[3]) / 2), LAST_ACTION * 2000);
        }
    }
    if(LAST_ACTION_STATE == STATE_IDLE) {
        writeDebugStreamLine("	Sleep(%d);",LAST_ACTION * 5);
    }
    LAST_ACTION = 0;
}

void writeLinesFromJoystick(int y1, int y2) {
    if(y1 > 40 && y2 > 40) {
        if(LAST_ACTION_STATE != STATE_FORWARD) {
            writePrevLine();
            LAST_ACTION_STATE = STATE_FORWARD;
        }
    } else if(y1 < -40 && y2 < -40) {
        if(LAST_ACTION_STATE != STATE_BACKWARD) {
            writePrevLine();
            LAST_ACTION_STATE = STATE_BACKWARD;
        }
    } else if(y1 > 40 && y2 < -40) {
        if(LAST_ACTION_STATE != STATE_LEFT) {
            writePrevLine();
            LAST_ACTION_STATE = STATE_LEFT;
        }
    } else if(y1 < -40 && y2 > 40) {
        if(LAST_ACTION_STATE != STATE_RIGHT) {
            writePrevLine();
            LAST_ACTION_STATE = STATE_RIGHT;
        }
    }

    LAST_ACTION = LAST_ACTION + 1;
}

void onJoy1PosUpdate(int x1, int y1, int x2, int y2) {
    int power1 = y1 * 0.78;
    int power2 = y2 * 0.78;

    if(y1 > 40 || y2 > 40 || y1 < -40 || y2 < -40) {
        int avgpower = (power1 + power2) / 2;

        power_data[3] = power_data[2];
        power_data[2] = power_data[1];
        power_data[1] = power_data[0];

        if(y1 > 40 && y2 < -40) {
            power_data[0] = y1;
        } else if(y1 < -40 && y2 > 40) {
            power_data[0] = y2;
        } else {
            if(avgpower > 40) {
                power_data[0] = avgpower;
            } else {
                power_data[0] = power_data[1];
            }
        }

        motor[LeftDrive] = power1;
        motor[RightDrive] = power2;
    }

    writeLinesFromJoystick(y1, y2);
}

void onJoy2PosUpdate(int x1, int y1, int x2, int y2) {

}

void displayInit() {
	bNxtLCDStatusDisplay = false;
	disableDiagnosticsDisplay();
	eraseDisplay();
}
