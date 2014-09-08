void writeInitCodeOutput() {
	writeDebugStreamLine("// **********");
	writeDebugStreamLine("// Run 'Motors and Sensors setup' before running the program!");
	writeDebugStreamLine("// **********");
	writeDebugStreamLine("");
	writeDebugStreamLine("// Generated from AutoPuppet");
	writeDebugStreamLine("");
	writeDebugStreamLine("void stopMotors() {");
	writeDebugStreamLine("	motor[LeftDrive] = 0;");
	writeDebugStreamLine("	motor[RightDrive] = 0;");
	writeDebugStreamLine("}");
	writeDebugStreamLine("void goForward(const int power, const int duration) {");
	writeDebugStreamLine("	motor[LeftDrive] = power;");
	writeDebugStreamLine("	motor[RightDrive] = power;");
	writeDebugStreamLine("	Sleep(duration);");
	writeDebugStreamLine("	stopMotors();");
	writeDebugStreamLine("}");
	writeDebugStreamLine("");
	writeDebugStreamLine("void goBackward(const int power, const int duration) {");
	writeDebugStreamLine("	motor[LeftDrive] = -power;");
	writeDebugStreamLine("	motor[RightDrive] = -power;");
	writeDebugStreamLine("	Sleep(duration);");
	writeDebugStreamLine("	stopMotors();");
	writeDebugStreamLine("}");
	writeDebugStreamLine("");
	writeDebugStreamLine("void turn(const int powerLeft, const int powerRight, const int duration) {");
	writeDebugStreamLine("	motor[LeftDrive] = powerLeft;");
	writeDebugStreamLine("	motor[RightDrive] = powerRight;");
	writeDebugStreamLine("	Sleep(duration);");
	writeDebugStreamLine("	stopMotors();");
    writeDebugStreamLine("}");

	writeDebugStreamLine("task main() {");
	writeDebugStreamLine("	bMotorReflected[LeftDrive] = true;");
}

void writeEndingCodeOutput() {
	writeDebugStreamLine("}");
}

void writeInitDebugLines() {
	writeDebugStreamLine("Autopuppet v1.0.0");
	writeDebugStreamLine("---");
	writeDebugStreamLine("By williamtdr - github.com/williamtdr");
	writeDebugStreamLine("");
	writeDebugStreamLine("Waiting for you to start the program.");
	writeDebugStreamLine("Place your hand on the joystick and move your robot into position.");
	writeDebugStreamLine("When you're ready to start, set the mode to Teleop: Running.");
	writeDebugStreamLine("");
}

void writeOnRunDebugLines() {
	writeDebugStreamLine("Logging code output.");
	writeDebugStreamLine("Don't forget to add your motor config to the beginning of the output.");
	writeDebugStreamLine("");
	writeDebugStreamLine("---");
}

void writeOnStopDebugLines() {
	writeDebugStreamLine("---");
    writeDebugStreamLine("Process complete!");
}