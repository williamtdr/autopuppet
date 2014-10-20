task main() {
    motorsSetup();

    switchState(STATE_WAIT);

    waitForStart();

    StartTask(tick);
    switchState(STATE_RUN);
    while(systemState.stopped == false) {
        Sleep(1000);
    }

    Sleep(30000);  // give the user a chance to see the message
}