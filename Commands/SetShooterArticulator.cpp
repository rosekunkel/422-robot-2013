#include "SetShooterArticulator.h"
#ifndef USE_PISTON_ARTICULATOR
#include <cmath>

const float SetShooterArticulator::MAX_ERROR = 0.02;

/// angle is in radians
SetShooterArticulator::SetShooterArticulator(float angle) {
	Requires(shooterArticulator);
	setpoint = angle;
}

// Called repeatedly when this Command is scheduled to run
void SetShooterArticulator::Execute() {
	if ( shooterArticulator->getAngle() > setpoint ) {
		shooterArticulator->moveDown();
	} else if ( shooterArticulator->getAngle() < setpoint ) {
		shooterArticulator->moveDown();
	} else {
		shooterArticulator->stop();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool SetShooterArticulator::IsFinished() {
	return fabs(shooterArticulator->getAngle() - setpoint) <= MAX_ERROR;
}

// Called once after isFinished returns true
void SetShooterArticulator::End() {
	shooterArticulator->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetShooterArticulator::Interrupted() {
	shooterArticulator->stop();
}
#endif
