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
	bool wait;
	bool stopped;
	bool running;
} systemStateForm;

systemStateForm systemState;

const int STATE_WAIT = 1;
const int STATE_RUN = 2;
const int STATE_STOP = 3;

int TIME_PASSED = 0;
int TICK_HUNDREDS = 1;

int LAST_ACTION = 0;

typedef enum LAST_ACTION_STATE_FORM {
	STATE_IDLE = 0,
	STATE_FORWARD = 1,
	STATE_BACKWARD = 2,
	STATE_LEFT = 3,
    STATE_RIGHT = 4
} LAST_ACTION_STATE_FORM;

LAST_ACTION_STATE_FORM LAST_ACTION_STATE;

int power_data[4] = {0, 0, 0, 0};