/**
* @file OI.H
* @brief Declaration of the Operator Interface
* @author Nyle Rodgers
*/

#ifndef OI_H
#define OI_H


/**
* @brief The operator interface
*
* Interfaces between the operater and the code/robot.
*/
#include "WPILib.h"

class OI {
private:
	Joystick *leftPrimaryJoystick,
	         *rightPrimaryJoystick,
	         *secondaryJoystick;
public:
	/// Initilize the OI.
	OI();
	Joystick* getLeftPrimaryJoystick();
	Joystick* getRightPrimaryJoystick();
	Joystick* getSecondaryJoystick();
	
	
};

#endif // OI_H
