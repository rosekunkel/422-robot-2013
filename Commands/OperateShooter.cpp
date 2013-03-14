#include "OperateShooter.h"
#ifndef USE_BANG_BANG

OperateShooter::OperateShooter() {
	Requires(shooter);
	dashboard = DriverStationLCD::GetInstance();
}

// Called repeatedly when this Command is scheduled to run
void OperateShooter::Execute() {
	// This part operates the shooter wheels
	if ( operatorInterface->stopShooterButtonPressed() ) {
		shooter->stopShooter();
	}
	else if ( operatorInterface->lowSetpointButtonPressed() ) {
		shooter->setSetpoints(20.0, 20.0);
	}
	else if ( operatorInterface->midSetpointButtonPressed() ) {
		shooter->setSetpoints(30.0, 30.0);
	}
	else if ( operatorInterface->highSetpointButtonPressed() ) {
		shooter->setSetpoints(40.0, 40.0);
	}
	
	dashboard->Clear();
	if ( shooter->isAtSpeed() ) {
		dashboard->Printf(DriverStationLCD::kUser_Line1, 1, "At Speed");
	}
	else {
		dashboard->Printf(DriverStationLCD::kUser_Line1, 1, "Spinning up");
	}
	dashboard->Printf(DriverStationLCD::kUser_Line2, 1, "%g", shooter->getFirstWheelSpeed() );
	dashboard->Printf(DriverStationLCD::kUser_Line3, 1, "%g", shooter->getSecondWheelSpeed() );
	dashboard->UpdateLCD();
}

// Make this return true when this Command no longer needs to run execute()
bool OperateShooter::IsFinished() {
	return false;
}

#endif
