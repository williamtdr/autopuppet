int heartbeat = 0;

task tick() {
	while(systemState.stopped == false) {
		Sleep(10);
		heartbeat = heartbeat + 1;
		onTick(heartbeat);
	}
}