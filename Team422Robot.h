/**
* @file Team422Robot.h
* @brief Declaration of the main class for the robot
* @author Nyle Rodgers
*/

#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/StartShooterPusher.h"
#include "CommandBase.h"

class Team422Robot : public IterativeRobot {
private:
	Command *startShooterPusher;
	LiveWindow *liveWindow;
	
	void RobotInit();
	
	void AutonomousInit();
	
	void AutonomousPeriodic();
	
	void TeleopInit();
	
	void TeleopPeriodic();
	
	void TestPeriodic();
};

START_ROBOT_CLASS(Team422Robot);

