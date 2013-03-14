#include "BangBangShooterControl.h"

#ifdef USE_BANG_BANG
BangBangShooterControl::BangBangShooterControl() {
	firstWheelSetpoint = 0.0;
	secondWheelSetpoint = 0.0;
	dashboard = DriverStationLCD::GetInstance();
}

// Called just before this Command runs the first time
void BangBangShooterControl::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void BangBangShooterControl::Execute() {
	if ( operatorInterface->stopShooterButtonPressed() ) {
		firstWheelSetpoint = 0.0;
		secondWheelSetpoint = 0.0;
	}
	else if ( operatorInterface->lowSetpointButtonPressed() ) {
		firstWheelSetpoint = 20.0;
		secondWheelSetpoint = 20.0;
	}
	else if ( operatorInterface->midSetpointButtonPressed() ) {
		firstWheelSetpoint = 30.0;
		secondWheelSetpoint = 30.0;
	}
	else if ( operatorInterface->highSetpointButtonPressed() ) {
		firstWheelSetpoint = 40.0;
		secondWheelSetpoint = 40.0;
	}
	
	// Control First Wheel
	if( shooter->getFirstWheelSpeed() < firstWheelSetpoint ) {
		shooter->runFirstWheel();
	}
	else {
		shooter->coastFirstWheel();
	}
	
	// Control Second Wheel
	if( shooter->getSecondWheelSpeed() < secondWheelSetpoint ) {
		shooter->runSecondWheel();
	}
	else {
		shooter->coastSecondWheel();
	}
	
	dashboard->Clear();
	dashboard->Printf(DriverStationLCD::kUser_Line1, 1, "%f", 
			shooter->getFirstWheelSpeed() - firstWheelSetpoint );
	dashboard->Printf(DriverStationLCD::kUser_Line2, 1, "%f", 
			shooter->getSecondWheelSpeed() - secondWheelSetpoint );
	dashboard->UpdateLCD();
}

// Make this return true when this Command no longer needs to run execute()
bool BangBangShooterControl::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void BangBangShooterControl::End() {
	shooter->coastFirstWheel();
	shooter->coastSecondWheel();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BangBangShooterControl::Interrupted() {
	shooter->coastFirstWheel();
	shooter->coastSecondWheel();
}
#endif
