#include "OperateShooter.h"
#include <cmath>
#include <iostream>

float p = 0.02;

OperateShooter::OperateShooter() {
	Requires(shooter);
}

// Called repeatedly when this Command is scheduled to run
void OperateShooter::Execute() {
//	float firstSpeed = operatorInterface->getLeftPrimaryJoystick()->GetY();
//	float secondSpeed = operatorInterface->getRightPrimaryJoystick()->GetY();
//	if (operatorInterface->getLeftPrimaryJoystick()->GetTrigger()) {
//		firstSpeed = 1.0;
//	}
//	if (operatorInterface->getRightPrimaryJoystick()->GetTrigger()) {
//		secondSpeed = 1.0;
//	}
//	shooter->setFirstMotorSpeed(firstSpeed);
//	shooter->setSecondMotorSpeed(secondSpeed);
	
	if (operatorInterface->getLeftPrimaryJoystick()->GetTrigger()) {
		shooter->startShooter();
	} else if (operatorInterface->getRightPrimaryJoystick()->GetTrigger()) {
		shooter->stopShooter();
	}
	float tempP = ( -operatorInterface
			        ->getLeftPrimaryJoystick()
			        ->GetZ() + 1.0) / 2.0 * 0.03;
	if ( fabs(p - tempP) > 0.001) {
		p = tempP;
		std::cerr << p << std::endl;
		shooter->setP(p);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool OperateShooter::IsFinished() {
	return false;
}
