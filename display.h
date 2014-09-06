task updateDisplay() {
	if(systemState.waitingStart) {
		nxtDisplayCenteredTextLine(0,"AutoPuppet");
		nxtDisplayCenteredTextLine(1,"---");
		nxtDisplayCenteredTextLine(2,"Waiting for a");
		nxtDisplayCenteredTextLine(3,"connection from");
		nxtDisplayCenteredTextLine(4,"the Field Control");
		nxtDisplayCenteredTextLine(5,"System. Check that");
		nxtDisplayCenteredTextLine(6,"this is set as the");
		nxtDisplayCenteredTextLine(7,"TeleOp program.");
	}
}

void displayInit() {
	bNxtLCDStatusDisplay = true;
	eraseDisplay();
}