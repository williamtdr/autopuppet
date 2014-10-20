///////////////////////////////
//							 //
// 		Puppet Settings 	 //
//							 //
///////////////////////////////

/*
 * Here you change motors are reflected (if any).
 * Reflected motors turn positive values they are passed
 * for the speed at which they should move into negative
 * values. Most robots have both of their motors wired
 * positve-to-positve for the left and right drive on
 * the motor controller, with the left drive therefore
 * needing to be reversed. That's the default that's provided
 * here. If your robot starts spinning when you go forward on
 * the joystick, comment out this line. Some cases might
 * require you to switch 'LeftDrive' to 'RightDrive'.
 */
void motorsSetup() {
    bMotorReflected[LeftDrive] = true;
}

/*
 * This is the threshold for error on the joysticks, the tolerance
 * for when the robot should be stopped. The joysticks usually don't
 * go to exactly 0 when stopped, so this compensates for that fact.
 * If your robot is sometimes moving forward slowly when your hands
 * are off the joysticks, increase this value.
 */

const int JOYSTICK_PRECISION = 40;
