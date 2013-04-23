/**
 * @file CheesyDrive.cpp
 * @brief Implementation of the CheesyDrive command
 * @author William Kunkel
 */
#include "WPILib.h"
#include "CheesyDrive.h"
#include "../RobotMap.h"

#ifdef USE_CPP_11
#include <cmath>
#endif

const float CheesyDrive::DEADZONE = 0.1;

/**
 * Give the subsystem requirements for CheesyDrive.
 *
 * @author William Kunkel
 */
CheesyDrive::CheesyDrive() :
	forwardMultiplier( 1.0 ),
	turningMultiplier( 0.5 ),
	tankDrive( true ) {
	Requires(drive);
}

/**
 * Drive the robot, using the left primary joystick to control forward-and-back
 * motion, and the right primary joystick to control turning.
 *
 * @author William Kunkel
 */
void CheesyDrive::Execute() {
	updateMultipliers();
	if( tankDrive ) {
#ifdef USE_PS3_CONTROLLER
		float left = operatorInterface
					 ->getPrimaryJoystick()
					 ->GetRawAxis(PS3_LEFT_Y);
		float right = operatorInterface
					  ->getPrimaryJoystick()
					  ->GetRawAxis(PS3_RIGHT_Y);
#else
		float left = operatorInterface
					 ->getLeftPrimaryJoystick()
					 ->GetY();
		float right = operatorInterface
					  ->getRightPrimaryJoystick()
					  ->GetY();
#endif
		drive->setMotorsNormalizedDirect( left * forwardMultiplier,
			                              right * forwardMultiplier );
	}
	else {
#ifdef USE_PS3_CONTROLLER
		float forward = operatorInterface
						->getPrimaryJoystick()
						->GetRawAxis(PS3_LEFT_Y);
		float turning = operatorInterface
						->getPrimaryJoystick()
						->GetRawAxis(PS3_RIGHT_X);
#else
		float forward = operatorInterface
						->getLeftPrimaryJoystick()
						->GetY();
		float turning = operatorInterface
						->getRightPrimaryJoystick()
						->GetX();
#endif
		// We add a dead zone around 0 to circumvent joysticks not being perfectly centered
		forward = valueWithDeadzone( forward, DEADZONE );
		turning = valueWithDeadzone( turning, DEADZONE );
	
		// Scale the values by the multiplier we selected
		forward *= forwardMultiplier;
		turning *= turningMultiplier;
	
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

float CheesyDrive::valueWithDeadzone( float value, const float deadzone ) {
	if( deadzone >= 1 ) {
		return 0.0;
	}

	if( value > 0.0) {
   		value = (value - deadzone) / (1.0 - deadzone);
		if (value < 0.0) {
			value = 0.0;
		}
	}
	else {
		value = (value + deadzone) / (1.0 - deadzone);
		if (value > 0.0) {
			value = 0.0;
		}
	}

	return value;
}

float CheesyDrive::truncateOutOfBounds( float value ) {
	if( ( value > 1 )
	 || ( value < -1 ) ) {
		// We set the multiplier to +-100%, based on its original sign
#ifdef USE_CPP_11
		value = std::copysign( 1.0, value )
#else
		value = ((0.0 < value) - (value < 0.0));
#endif
	}

	return value;
}

void CheesyDrive::updateMultipliers() {
   	if( operatorInterface->lowSpeedButtonPressed() ) {
		forwardMultiplier = 0.5;
		tankDrive = true;
	}
	else if( operatorInterface->halfSpeedButtonPressed() ) {
		forwardMultiplier = 0.5;
		tankDrive = true;
	}
	else if( operatorInterface->fullSpeedButtonPressed() ) {
		forwardMultiplier = 1.0;
		tankDrive = true;
	}

	if( operatorInterface->quarterTurnSpeedButtonPressed() ) {
		turningMultiplier = 0.25;
	}
	else if( operatorInterface->halfTurnSpeedButtonPressed() ) {
		turningMultiplier = 0.5;
	}
	else if( operatorInterface->fullTurnSpeedButtonPressed() ) {
		turningMultiplier = 1.0;
	}
}
