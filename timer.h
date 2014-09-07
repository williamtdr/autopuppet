void onTick() {
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
}

task runTimer() {
	while(systemState.stopped == false) {
		Sleep(1000);
		TIME_PASSED = TIME_PASSED + 1;
		onTick();
		if(TIME_PASSED == 30) {
			switchState(STATE_STOP);
		}
	}
}