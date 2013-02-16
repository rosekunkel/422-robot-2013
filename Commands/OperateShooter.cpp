#include "OperateShooter.h"
#include <cmath>
#include <iostream>

OperateShooter::OperateShooter() {
	Requires(shooter);
}

// Called repeatedly when this Command is scheduled to run
void OperateShooter::Execute() {
	// This part operates the shooter wheels
	if ( operatorInterface
		 ->getSetpointOneButtonValue() ) {
		shooter->setSetpoints(20.0, 20.0);
	} else if ( operatorInterface
			    ->getSetpointTwoButtonValue() ) {
		shooter->setSetpoints(30.0, 30.0);
	} else if ( operatorInterface
		        ->getSetpointThreeButtonValue() ) {
		shooter->setSetpoints(40.0, 40.0);
	} else if ( operatorInterface->getSecondaryJoystick()->GetRawButton(2) ) {// TODO: do this correctly (throughOI)
		shooter->stopShooter();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool OperateShooter::IsFinished() {
	return false;
}
