/**
 * @file Team422Robot.h
 * @brief Declaration of the main class for the robot
 * @author Nyle Rodgers
 * @author William Kunkel
 */

#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Commands/CheesyDrive.h"
#include "Commands/MoveShooterArticulator.h"
#include "Commands/OperateShooter.h"
#include "Commands/OperateShooterArticulator.h"
#include "Commands/RaiseClimber.h"
#include "Commands/SetShooterArticulator.h"
#include "Commands/Shoot.h"
#include "Commands/SpinHalfRotation.h"
#include "Commands/ToggleClimber.h"

/**
 * @brief The main class for the robot
 * 
 * The class that controls the main operation of the robot. It defines the
 * sequence of actions to run during each phase of the robot's operation.
 *
 * @author Nyle Rodgers
 * @author William Kunkel
 */
class Team422Robot : public IterativeRobot {
private:
	Command *cheesyDrive,
	        *moveShooterArticulator,
	        *operateShooter,
	        *operateShooterArticulator,
	        *raiseClimber,
	        *setShooterArticulator,
	        *shoot;

	DriverStationLCD *dashboard;
	LiveWindow *liveWindow;

	/// Robot-wide initialization code
	void RobotInit();

	/// Initialization for autonomous phase 
	void AutonomousInit();

	/// Run periodically during the autonomous phase
	void AutonomousPeriodic();

	/// Initialization for the teleoperated phase
	void TeleopInit() {};

	/// Run periodically during the teleoperated phase
	void TeleopPeriodic();

	/// Run periodically when the robot is in test mode
	void TestPeriodic();
};
