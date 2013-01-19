#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/StartShooterPusher.h"
#include "CommandBase.h"

class CommandBasedRobot : public IterativeRobot {
private:
	Command *autonomousCommand;
	Command *startShooterPusher;
	LiveWindow *lw;
	
	virtual void RobotInit() {
		CommandBase::init();
		//autonomousCommand = ;// TODO: Put an autonomous command in here
		startShooterPusher = new StartShooterPusher;
		lw = LiveWindow::GetInstance();
	}
	
	virtual void AutonomousInit() {
		startShooterPusher->Start();
		autonomousCommand->Start();
	}
	
	virtual void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TeleopInit() {
		autonomousCommand->Cancel();
	}
	
	virtual void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TestPeriodic() {
		lw->Run();
	}
};

START_ROBOT_CLASS(CommandBasedRobot);

