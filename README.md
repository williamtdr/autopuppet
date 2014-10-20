Autopuppet
==========

A program that takes joystick movements and turns them into a modifiable autonomous program in ROBOTC.

Setup instructions:

1. Download the latest version of autopuppet from the 'Download ZIP' option on the side of the page. Extract the downloaded .zip file (right click -> extract all should work on most Windows systems)
2. Open puppet.c in ROBOTC, and connect to your robot via USB, Bluetooth or Wifi (Platform > NXT Brick > Communication Link Setup). Bluetooth or wifi is preferable, as then you can create your autonomous program wirelessly.
3. Set your window level to 'Super User' to see all available options.
4. Modify the Motors & Sensors information (in puppet.c) at the top of the program to fit your robot setup. There's additional configuration information in the block comment after the motor configuration for additional options and help.
5. Compile and download the program. Go to Robot -> Debugger windows and enable the Joystick Control - FTC and Debug Stream options.
6. Change the teleop program to puppet.rxe, then set the mode to Tele-Op: Ready. If you've set everything up right, you should see some text in the debug stream window saying the current version and some basic instructions.
7. Set up your robot and check that the controller is working properly, then set the mode to Tele-Op: Running. Move your robot around in the fashion you want it to go during autonomous.
8. When you see the text 'Process complete!' and the robot stops moving, then the 30 seconds is up. Copy and paste the text between the two '---' sections into a new file for your autonomous code, and paste in your motors and sensors setup at the top. You can then compile and download that program and use it as your autonomous mode.

That's it! If you need help, please open an issue or contact me below the FTC forum post for this program, I'd be glad to help. Code contributions are welcome, if you can think of way to do something more efficently or better, please make a pull request.