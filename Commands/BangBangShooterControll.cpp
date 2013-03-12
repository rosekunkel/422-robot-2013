#include "BangBangShooterControll.h"

BangBangShooterControll::BangBangShooterControll() {
	firstWheelSetpoint = 0.0;
	secondWheelSetpoint = 0.0;
	dashboard = DriverStationLCD::GetInstance();
}

// Called just before this Command runs the first time
void BangBangShooterControll::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void BangBangShooterControll::Execute() {
	if ( operatorInterface->getSetpointZeroButtonValue() ) {
		firstWheelSetpoint = 0.0;
		secondWheelSetpoint = 0.0;
	} else if ( operatorInterface->getSetpointOneButtonValue() ) {
		firstWheelSetpoint = 20.0;
		secondWheelSetpoint = 20.0;
	} else if ( operatorInterface->getSetpointTwoButtonValue() ) {
		firstWheelSetpoint = 30.0;
		secondWheelSetpoint = 30.0;
	} else if ( operatorInterface->getSetpointThreeButtonValue() ) {
		firstWheelSetpoint = 40.0;
		secondWheelSetpoint = 40.0;
	}
	// Controll First Wheel
	if( shooter->getFirstWheelSpeed() < firstWheelSetpoint ) {
		shooter->setFirstWheelOn(true);
	}
	else {
		shooter->setFirstWheelOn(false);
	}
	// Controll Second Wheel
	if( shooter->getSecondWheelSpeed() < secondWheelSetpoint ) {
		shooter->setSecondWheelOn(true);
	}
	else {
		shooter->setSecondWheelOn(false);
	}
	dashboard->Clear();
	dashboard->Printf(DriverStationLCD::kUser_Line1, 1, "%f", 
			shooter->getFirstWheelSpeed() - firstWheelSetpoint );
	dashboard->Printf(DriverStationLCD::kUser_Line2, 2, "%f", 
			shooter->getSecondWheelSpeed() - secondWheelSetpoint );
	dashboard->UpdateLCD();
}

// Make this return true when this Command no longer needs to run execute()
bool BangBangShooterControll::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void BangBangShooterControll::End() {
	shooter->stopShooter();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BangBangShooterControll::Interrupted() {
	shooter->stopShooter();
}
