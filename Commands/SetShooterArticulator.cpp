#include "SetShooterArticulator.h"
#ifndef USE_PISTON_ARTICULATOR
#include <cmath>

#include <iostream>

const float SetShooterArticulator::MAX_ERROR = 0.05;

/// angle is in radians
SetShooterArticulator::SetShooterArticulator(float displacement) {
	Requires(shooterArticulator);
	setpoint = displacement;
	std::cerr << "Entered SetShooterArticulator" << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void SetShooterArticulator::Execute() {
	if ( shooterArticulator->getDisplacement() > setpoint ) {
		shooterArticulator->moveUp();
	}
	else if ( shooterArticulator->getDisplacement() < setpoint ) {
		shooterArticulator->moveDown();
	}
	else {
		shooterArticulator->stop();
	}
	std::cerr << "Running SetShooterArticulator" << std::endl;
}

// Make this return true when this Command no longer needs to run execute()
bool SetShooterArticulator::IsFinished() {
	std::cerr << "Displacement: " << shooterArticulator->getDisplacement() << std::endl;
	return fabs(shooterArticulator->getDisplacement() - setpoint) <= MAX_ERROR;
}

// Called once after isFinished returns true
void SetShooterArticulator::End() {
	shooterArticulator->stop();
	std::cerr << "Finished SetShooterArticulator" << std::endl;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetShooterArticulator::Interrupted() {
	shooterArticulator->stop();
	std::cerr << "Interrupted SetShooterArticulator" << std::endl;
}
#endif
