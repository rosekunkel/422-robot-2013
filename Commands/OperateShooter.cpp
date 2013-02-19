#include "OperateShooter.h"
#include "../Team422Robot.h"
#include <cmath>
#include <iostream>

OperateShooter::OperateShooter() {
	Requires(shooter);
	dashboard = DriverStationLCD::GetInstance();
}

// Called repeatedly when this Command is scheduled to run
void OperateShooter::Execute() {
	// This part operates the shooter wheels
	if ( operatorInterface->getSetpointZeroButtonValue() ) {
		shooter->stopShooter();
	 }else if ( operatorInterface->getSetpointOneButtonValue() ) {
		shooter->setSetpoints(30.0, 30.0);
	} else if ( operatorInterface->getSetpointTwoButtonValue() ) {
		shooter->setSetpoints(40.0, 40.0);
	} else if ( operatorInterface->getSetpointThreeButtonValue() ) {
		shooter->setSetpoints(55.0, 55.0);
	}
	dashboard->Clear();
	dashboard->Printf(DriverStationLCD::kUser_Line1, 1, "1: %f", shooter->getFirstWheelSpeed() );
	dashboard->Printf(DriverStationLCD::kUser_Line2, 1, "2: %f", shooter->getSecondWheelSpeed() );
	dashboard->Printf(DriverStationLCD::kUser_Line3, 1, "1: %f", shooter->getFirstWheelOfset() );
	dashboard->Printf(DriverStationLCD::kUser_Line4, 1, "2: %f", shooter->getSecondWheelOfset() );
	dashboard->Printf(DriverStationLCD::kUser_Line5, 1, "%b", ( shooter->isAtSpeed() )?"T":"F" );
	dashboard->UpdateLCD();
}

// Make this return true when this Command no longer needs to run execute()
bool OperateShooter::IsFinished() {
	return false;
}
