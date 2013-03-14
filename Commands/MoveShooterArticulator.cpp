/**
 * @file MoveShooterArticulator.cpp
 * @brief Implementation of the MoveShooterArticulator command
 * @author Nyle Rodgers
 */
#include "MoveShooterArticulator.h"

#include <cmath>

// TODO: Set an acceptable error
const float MoveShooterArticulator::MAX_ERROR = 0.0;

MoveShooterArticulator::MoveShooterArticulator( float angle ) :
	setpoint( angle ) {
	Requires(shooterArticulator);
}

// Called just before this Command runs the first time
void MoveShooterArticulator::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void MoveShooterArticulator::Execute() {
	if( shooterArticulator->getAngle() < setpoint ) {
		shooterArticulator->moveUp();
	} else if ( shooterArticulator->getAngle() > setpoint ){
		shooterArticulator->moveDown();
	} else {
		shooterArticulator->stop();
	}
	
}

// Make this return true when this Command no longer needs to run execute()
bool MoveShooterArticulator::IsFinished() {
	return fabs( shooterArticulator->getAngle() - setpoint ) <= MAX_ERROR;
}
