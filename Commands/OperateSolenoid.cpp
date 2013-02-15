#include "OperateSolenoid.h"

OperateSolenoid::OperateSolenoid():
	isExtended( false ){
	Requires(shooter);
}

// Called repeatedly when this Command is scheduled to run
void OperateSolenoid::Execute() {
	bool extend = operatorInterface->getRightPrimaryJoystick()->GetTrigger();
	bool retract = operatorInterface->getLeftPrimaryJoystick()->GetTrigger();
	if (extend && !retract && !isExtended) {
		shooter->extend();
		isExtended = true;
	} else if (retract && !extend && isExtended) {
		shooter->retract();
		isExtended = false;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool OperateSolenoid::IsFinished() {
	return false;
}
