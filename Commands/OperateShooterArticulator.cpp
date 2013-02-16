#include "OperateShooterArticulator.h"

OperateShooterArticulator::OperateShooterArticulator() {
	Requires(shooterArticulator);
}

// Called repeatedly when this Command is scheduled to run
void OperateShooterArticulator::Execute() {
	if (operatorInterface->getSecondaryJoystick()->GetY() > 0.5) {
		shooterArticulator->moveUp();
	} else if (operatorInterface->getSecondaryJoystick()->GetY() < -0.5) {
		shooterArticulator->moveDown();
	} else {
		shooterArticulator->stop();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool OperateShooterArticulator::IsFinished() {
	return false;
}
