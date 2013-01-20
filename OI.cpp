/**
* @file OI.cpp
* @brief Implementation of the Operater Interface
* @author Nyle Rodgers
*/

#include "OI.h"

/**
 * Initilize the OI.
 *
 * @author Nyle Rodgers
 */
OI::OI() {
	leftPrimaryJoystick = new Joystick(1);
	rightPrimaryJoystick = new Joystick(2);
	secondaryJoystick = new Joystick(3);
}

/**
 * Get the left primary joystick.
 *
 * @author Nyle Rodgers
 */
Joystick* getLeftPrimaryJoystick() {
	return leftPrimaryJoystick;
}

/**
 * Get the right primary joystick.
 *
 * @author Nyle Rodgers
 */
Joystick* getRightPrimaryJoystick() {
	return rightPrimaryJoystick;
}

/**
 * Get the secondary joystick.
 *
 * @author Nyle Rodgers
 */
Joystick* getSecondaryJoystick() {
	return secondaryJoystick;
}
