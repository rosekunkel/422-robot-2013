#include "OperateShooterArticulator.h"
#include "../RobotMap.h"

OperateShooterArticulator::OperateShooterArticulator() {
	Requires(shooterArticulator);
}

// Called repeatedly when this Command is scheduled to run
void OperateShooterArticulator::Execute() {
#ifdef USE_GAMECUBE_CONTROLLER
	// The gamecube controller maps from 0.75 to -0.75, we need to adjust
	float y = operatorInterface
			  ->getSecondaryJoystick()
			  ->GetRawAxis(GC_LEFT_Y) * (-4/3);
#else
	float y = operatorInterface->getSecondaryJoystick()->GetY();
#endif
	if (y > 0.5) {
		shooterArticulator->moveUp();
	}
	else if (y < -0.5) {
		shooterArticulator->moveDown();
	}
	else {
		shooterArticulator->stop();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool OperateShooterArticulator::IsFinished() {
	return false;
}
