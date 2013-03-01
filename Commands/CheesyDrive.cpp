/**
 * @file CheesyDrive.cpp
 * @brief Implementation of the CheesyDrive command
 * @author William Kunkel
 */
#include "WPILib.h"
#include "CheesyDrive.h"
#include <iostream>

// We need <cmath> for copysignf in cheesyDrive
#include <cmath>

const float CheesyDrive::DEADZONE = 0.1;

/**
 * Give the subsystem requirements for CheesyDrive.
 *
 * @author William Kunkel
 */
CheesyDrive::CheesyDrive() {
	Requires(drive);
	multiplier = 1.0;
	forwardMultiplier = 1.0;
	turningMultiplier = 0.5;
}

/**
 * Drive the robot, using the left primary joystick to control forward-and-back
 * motion, and the right primary joystick to control turning.
 *
 * @author William Kunkel
 */
void CheesyDrive::Execute() {
	updateMultipliers();
	updateReverseStatus();

	if ( operatorInterface->getStopDriveButtonValue() ) {
		drive->stop();
	}
	else {
		float forward = operatorInterface
						->getLeftPrimaryJoystick()
						->GetY();
		float turning = operatorInterface
						->getRightPrimaryJoystick()
						->GetX();
		
		// We add a dead zone around 0 to circumvent joysticks not being perfectly centered
		forward = valueWithDeadzone( forward, DEADZONE );
		turning = valueWithDeadzone( turning, DEADZONE );

		// Scale the values by the multiplier we selected
		forward *= forwardMultiplier * multiplier;
		turning *= turningMultiplier * multiplier;
		
		if ( operatorInterface->getDriveReverseButtonValue() && !isReversePressed ) {
			forward = -forward;
		}

		// We determine the speed multiplier by adding and subtracting the turning
		// value from the base speed
		float leftMultiplier  = forward-turning,
			  rightMultiplier = forward+turning;
		
		// We need to make sure that our speed multiplier does not exceed 100%, but
		// simple scaling between -2 and 2 would limit linear top speed.	
		leftMultiplier  = truncateOutOfBounds( leftMultiplier );
		rightMultiplier = truncateOutOfBounds( rightMultiplier );

		// Set the speed, using the multiplier as a percentage of the top speed
		drive->setMotorsNormalized( leftMultiplier, rightMultiplier );
	}
}

/**
 * Driving never "finishes", so returns false
 *
 * @author William Kunkel
 */
bool CheesyDrive::IsFinished() {
	return false;
}

float CheesyDrive::valueWithDeadzone( float value, float deadzone ) {
	float newValue = 0.0;

	if( deadzone >= 1 ) {
		return 0.0;
	}

	if( value > 0.0) {
   		newValue = (value - deadzone) / (1.0 - deadzone);
		if (newValue < 0.0) {
			newValue = 0.0;
		}
	}
	else {
		newValue = (value + deadzone) / (1.0 - deadzone);
		if (newValue > 0.0) {
			newValue = 0.0;
		}
	}

	return newValue;
}

float CheesyDrive::truncateOutOfBounds( float value ) {
	float newValue = value;

	if( ( value > 1 )
	 || ( value < -1 ) ) {
		// We set the multiplier to +-100%, based on its original sign
		newValue = ((0.0 < newValue) - (newValue < 0.0));
	}

	return newValue;
}

void CheesyDrive::updateMultipliers() {
   	if ( operatorInterface->getOneTenthSpeedMultiplierButtonValue() ) {
		multiplier = 0.1;
	}
	else if ( operatorInterface->getHalfSpeedMultiplierButtonValue() ) {
		multiplier = 0.5;
	}
	else if ( operatorInterface->getFullSpeedButtonValue() ) {
		multiplier = 1.0;
	}

	if ( operatorInterface->getQuarterSpeedTurningMultiplierButtonValue() ) {
		turningMultiplier = 0.25;
	}
	else if ( operatorInterface->getHalfSpeedTurningMultiplierButtonValue() ) {
		turningMultiplier = 0.5;
	}
}

void CheesyDrive::updateReverseStatus() {
	if ( operatorInterface->getDriveReverseButtonValue() && !isReversePressed ) {
		isReversePressed = true;
	}
	else if ( !operatorInterface->getDriveReverseButtonValue() && isReversePressed ) {
		isReversePressed = false;
	}
}
