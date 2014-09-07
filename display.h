task updateDisplay() {
	while(systemState.stopped == false) {
		nxtDisplayCenteredTextLine(0,"AutoPuppet");
		nxtDisplayCenteredTextLine(1,"---");

		if(systemState.wait) {
			nxtDisplayCenteredTextLine(2,"Waiting for a");
			nxtDisplayCenteredTextLine(3,"connection from");
			nxtDisplayCenteredTextLine(4,"the Field Control");
			nxtDisplayCenteredTextLine(5,"System. Check that");
			nxtDisplayCenteredTextLine(6,"this is set as the");
			nxtDisplayCenteredTextLine(7,"TeleOp program.");
		}

		if(systemState.running) {
			nxtDisplayCenteredTextLine(2,"Running.");
            nxtDisplayCenteredTextLine(3,"Seconds passed: %d",TIME_PASSED);
		}

		if(systemState.stopped) {
			nxtDisplayCenteredTextLine(2,"30 second autonomous");
			nxtDisplayCenteredTextLine(3,"period completed.");
			nxtDisplayCenteredTextLine(4,"");
			nxtDisplayCenteredTextLine(5,"Resulting file");
			nxtDisplayCenteredTextLine(6,"saved to %s.",SAVED_FILE);
			nxtDisplayCenteredTextLine(7,"Press [  ] to stop.");
		}
		Sleep(100);
	}
}

void displayInit() {
	bNxtLCDStatusDisplay = true;
	disableDiagnosticsDisplay();
	eraseDisplay();
}