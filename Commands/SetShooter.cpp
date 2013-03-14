#include "SetShooter.h"

SetShooter::SetShooter( float setpoint ) :
	setpoint( setpoint ) {
	Requires(shooter);
}

void SetShooter::Initialize() {
	shooter->setSetpoint( setpoint );
}

bool SetShooter::IsFinished() {
	return true;
}
