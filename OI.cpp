/**
 * @file OI.cpp
 * @brief Implementation of the Operater Interface
 * @author Nyle Rodgers
 */

#include "OI.h"

/**
 * Initilize the Operator Interface.
 *
 * @author Nyle Rodgers
 */
OI::OI() {
	leftPrimaryJoystick = new Joystick(1);
	rightPrimaryJoystick = new Joystick(2);
	secondaryJoystick = new Joystick(3);
}

/**
 * Get the left joystick for the primary driver.
 *
 * @author Nyle Rodgers
 */
Joystick* OI::getLeftPrimaryJoystick() {
	return leftPrimaryJoystick;
}

/**
 * Get the right joystick for the primary driver.
 *
 * @author Nyle Rodgers
 */
Joystick* OI::getRightPrimaryJoystick() {
	return rightPrimaryJoystick;
}

/**
 * Get the joystick for the secondary driver.
 *
 * @author Nyle Rodgers
 */
Joystick* OI::getSecondaryJoystick() {
	return secondaryJoystick;
}
