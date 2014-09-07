task updateDisplay() {
	while(systemState.stopped == false) {
		nxtDisplayCenteredTextLine(0,"AutoPuppet");
		nxtDisplayCenteredTextLine(1,"---");

		if(systemState.wait) {
			nxtDisplayCenteredTextLine(2,"Waiting for a");
			nxtDisplayCenteredTextLine(3,"connection from");
			nxtDisplayCenteredTextLine(4,"the Field");
			nxtDisplayCenteredTextLine(5,"Control System.");
			nxtDisplayCenteredTextLine(6,"Ready when you");
			nxtDisplayCenteredTextLine(7,"are.");
		}

		if(systemState.running) {
			nxtDisplayCenteredTextLine(2,"Running.");
            nxtDisplayCenteredTextLine(3,"Seconds run: %d",TIME_PASSED);
            nxtDisplayCenteredTextLine(4,"");
            nxtDisplayCenteredTextLine(5,"");
            nxtDisplayCenteredTextLine(6,"");
            nxtDisplayCenteredTextLine(7,"");
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