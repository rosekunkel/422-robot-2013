#include "SpinHalfRotation.h"

SpinHalfRotation::SpinHalfRotation( bool left ) {
	Requires(drive);
	isLeft = left;
}

// Called just before this Command runs the first time
void SpinHalfRotation::Initialize( ) {
	drive->resetEncoders();
	if ( isLeft ) {
		drive->setMotorsNormalized( -1.0, 1.0 );
	} else {
		drive->setMotorsNormalized( 1.0, -1.0 );
	}
}

// Make this return true when this Command no longer needs to run execute()
bool SpinHalfRotation::IsFinished() {
	return ( drive->getAmountSpun() > 5.0416 ); //< got that number with math 
}

// Called once after isFinished returns true
void SpinHalfRotation::End() {
	drive->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpinHalfRotation::Interrupted() {
	drive->stop();
}
