/**
 * @file OI.h
 * @brief Declaration of the Operator Interface
 * @author Nyle Rodgers
 */

#ifndef OI_H
#define OI_H

#include "WPILib.h"

/**
 * @brief The operator interface
 *
 * Provides means for the robot code to access the operator interface through
 * Joystick objects, etc.
 *
 * @author Nyle Rodgers
 */
class OI {
public:
	/// Constructor for the Operator Interface
	OI();

	/// Get the left Joystick for the primary driver
	Joystick* getLeftPrimaryJoystick();
	/// Get the right Joystick for the primary driver
	Joystick* getRightPrimaryJoystick();
	/// Get the joystick for the secondary driver
	Joystick* getSecondaryJoystick();
private:
	Joystick *leftPrimaryJoystick,
	         *rightPrimaryJoystick,
	         *secondaryJoystick;
};

#endif // OI_H
