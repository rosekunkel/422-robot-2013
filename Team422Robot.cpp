/**
* @file Team422Robot.cpp
* @brief Implementation of the main class for the robot
* @author Nyle Rodgers
* @author William Kunkel
*/

#include "Team422Robot.h"

/**
 * Robot-wide initialization, such as allocating Commands.
 *
 * @author Nyle Rodgers
 * @author William Kunkel
 */
void Team422Robot::RobotInit() {
	CommandBase::init();
	startHopperWheel = new StartHopperWheel();
	cheesyDrive = new CheeseyDrive();
	liveWindow = LiveWindow::GetInstance();
}

/**
 * Commands and other code to run at the beginning of the autonomous phase
 *
 * @author Nyle Rodgers
 * @author William Kunkel
 */
void Team422Robot::AutonomousInit() {
	startHopperWheel->Start();
}

/**
 * Code to run periodically during the teleoperated phase, namely running the
 * scheduler
 *
 * @author Nyle Rodgers
 */
void Team422Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

/**
 * Code to run periodically during the autonomous phase, namely running the
 * scheduler
 *
 * @author Nyle Rodgers
 */
void Team422Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

/**
 * Code to run periodically while in test mode, like the Live Window
 *
 * @author Nyle Rodgers
 */
void Team422Robot::TestPeriodic() {
	liveWindow->Run();
}

// Start the robot, the equivalent of the "main" function
START_ROBOT_CLASS(Team422Robot);
