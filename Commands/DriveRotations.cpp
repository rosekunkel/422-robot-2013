#include "DriveRotations.h"
#include <cmath>

DriveRotations::DriveRotations( double rotations ) :
	rotationsToDrive( rotations ) {
	Requires(drive);
}

void DriveRotations::Initialize() {
	drive->resetEncoders();
	if( rotationsToDrive > 0 ) {
		drive->setMotorsNormalized( -1.0, -1.0 );
	}
	else if( rotationsToDrive < 0 ) {
		drive->setMotorsNormalized( 1.0, 1.0 );
	}
}

bool DriveRotations::IsFinished() {
	if( rotationsToDrive == 0 ) {
		return true;
	}
	return fabs( drive->getRotations() ) > fabs( rotationsToDrive );
}

void DriveRotations::End() {
	drive->stop();
}

void DriveRotations::Interrupted() {
	drive->stop();
}
