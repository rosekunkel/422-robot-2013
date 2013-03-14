#include "OperateShooter.h"
#ifndef USE_BANG_BANG

OperateShooter::OperateShooter() {
	Requires(shooter);
	dashboard = DriverStationLCD::GetInstance();
}

// Called repeatedly when this Command is scheduled to run
void OperateShooter::Execute() {
	// This part operates the shooter wheels
	if( operatorInterface->stopShooterButtonPressed() ) {
		shooter->stopShooter();
	}
	else if( operatorInterface->lowSetpointButtonPressed() ) {
		shooter->setSetpoints(20.0, 20.0);
		leftSetpoint = 20.0;
		rightSetpoint = 20.0;
	}
	else if( operatorInterface->midSetpointButtonPressed() ) {
		shooter->setSetpoints(30.0, 30.0);
		leftSetpoint = 30.0;
		rightSetpoint = 30.0;
	}
	else if( operatorInterface->highSetpointButtonPressed() ) {
		shooter->setSetpoints(40.0, 40.0);
		leftSetpoint = 40.0;
		rightSetpoint = 40.0;
	}
	
	if( operatorInterface->increaseSetpointButtonPressed()
		&& !isIncreaseButtonPressed ) {
		isIncreaseButtonPressed = true;
		shooter->setSetpoints( ++leftSetpoint, ++rightSetpoint );
	}
	else if( !operatorInterface->increaseSetpointButtonPressed() ) {
		isIncreaseButtonPressed = false;
	}

	if( operatorInterface->decreaseSetpointButtonPressed()
		&& !isDecreaseButtonPressed ) {
		isDecreaseButtonPressed = true;
		shooter->setSetpoints( --leftSetpoint, --rightSetpoint );
	}
	else if( !operatorInterface->decreaseSetpointButtonPressed() ) {
		isDecreaseButtonPressed = false;
	}
	
	dashboard->Clear();
	if ( shooter->isAtSpeed() ) {
		dashboard->Printf(DriverStationLCD::kUser_Line1, 1, "At Speed");
	}
	else {
		dashboard->Printf(DriverStationLCD::kUser_Line1, 1, "Spinning up");
	}
	dashboard->PrintfLine(DriverStationLCD::kUser_Line2, "%f", shooter->getFirstWheelSpeed() );
	dashboard->PrintfLine(DriverStationLCD::kUser_Line3, "%f", shooter->getSecondWheelSpeed() );
	dashboard->UpdateLCD();
}

// Make this return true when this Command no longer needs to run execute()
bool OperateShooter::IsFinished() {
	return false;
}

#endif
