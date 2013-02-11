/**
 * @file CheesyDrive.cpp
 * @brief Implementation of the CheesyDrive command
 * @author William Kunkel
 */
#include "WPILib.h"
#include "CheesyDrive.h"
#include <iostream>

// We need <math.h> for copysignf in cheesyDrive
#include <cmath>

/**
 * Give the subsystem requirements for CheesyDrive.
 *
 * @author William Kunkel
 */
CheesyDrive::CheesyDrive() {
	Requires(drive);
}

/**
 * Drive the robot, using the left primary joystick to control forward-and-back
 * motion, and the right primary joystick to control turning.
 *
 * @author William Kunkel
 */
void CheesyDrive::Execute() {
	deadzone = 0.1;
	float forward = operatorInterface
	                 ->getLeftPrimaryJoystick()
	                 ->GetY();
	float turning = 0.5 * operatorInterface
	                 ->getRightPrimaryJoystick()
	                 ->GetX();
	
	// We add a dead zone around 0 to circumvent joysticks not being perfectly centered
	if( forward > 0.0) {
		forward = (forward - deadzone) / (1.0 - deadzone);
		if (forward < 0.0) {
			forward = 0.0;
		}
	} else {
		forward = (forward + deadzone) / (1.0 - deadzone);
		if (forward > 0.0) {
			forward = 0.0;
		}
	}	
	if( turning > 0.0) {
		turning = (turning - deadzone) / (1.0 - deadzone);
		if (turning < 0.0) {
			turning = 0.0;
		}
	} else {
		turning = (turning + deadzone) / (1.0 - deadzone);
		if (turning > 0.0) {
			turning = 0.0;
		}
	}
	// We determine the speed multiplier by adding and subtracting the turning
	// value from the base speed
	float leftMultiplier = forward-turning,
	      rightMultiplier = forward+turning;
	
	// We need to make sure that our speed multiplier does not exceed 100%, but
	// simple scaling between -2 and 2 would limit linear top speed.	
	if( ( leftMultiplier > 1 )
	 || ( leftMultiplier < -1 ) ) {
		// We set the multiplier to +-100%, based on it's original sign
		leftMultiplier = ((0.0 < leftMultiplier) - (leftMultiplier < 0.0));
	}

	// Repeat with the right multiplier
	if( ( rightMultiplier > 1 )
	 || ( rightMultiplier < -1 ) ) {
		rightMultiplier = ((0.0 < rightMultiplier) - (rightMultiplier < 0.0));
	}

	// Set the speed, using the multiplier as a percentage of the top speed
	drive->setMotorsNormalized( leftMultiplier, rightMultiplier );
}

void CheesyDrive::Interrupted() {
	drive->stop();
}
/**
 * Driving never "finishes", so returns false
 *
 * @author William Kunkel
 */
bool CheesyDrive::IsFinished() {
	return false;
}
