/**
* @file Team422Robot.cpp
* @brief Implementation of the main class for the robot
* @author Nyle Rodgers
*/

#include "Team422Robot.h"

/**
 * Initialization code for the robot.
 *
 * @author Nyle Rodgers
 */
void Team422Robot::RobotInit() {
	CommandBase::init();
	startShooterPusher = new StartShooterPusher();
	liveWindow = LiveWindow::GetInstance();
}

/**
 * Initialization code for autonomous.
 *
 * @author Nyle Rodgers
 */
void Team422Robot::AutonomousInit() {
	startShooterPusher->Start();
}

/**
 * Periodic code for autonomous.
 *
 * @author Nyle Rodgers
 */
void Team422Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

/**
 * Initialization code for Teleoperated.
 *
 * @author Nyle Rodgers
 */
void Team422Robot::TeleopInit() {
	
}

/**
 * Periodic code for autonomous.
 *
 * @author Nyle Rodgers
 */
void Team422Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

/**
 * Periodic code for Test.
 *
 * @author Nyle Rodgers
 */
void Team422Robot::TestPeriodic() {
	liveWindow->Run();
}

