typedef struct {
	int joy1_y1;
	int joy1_y2;
	int joy1_x1;
	int joy1_x2;

	int joy2_y1;
	int joy2_y2;
	int joy2_x1;
	int joy2_x2;
} joystickStateForm;

joystickStateForm joystickState;

typedef struct {
	bool waitingStart;
	bool stopped;
	bool running;
} systemStateForm;

systemStateForm systemState;

const int STATE_WAIT = 1;
const int STATE_RUN = 2;
const int STATE_STOP = 3;