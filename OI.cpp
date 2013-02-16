/**
 * @file OI.cpp
 * @brief Implementation of the Operater Interface
 * @author Nyle Rodgers
 */

#include "OI.h"
#include "Commands/Shoot.h"

/**
 * Initilize the Operator Interface.
 *
 * @author Nyle Rodgers
 */
OI::OI():
	leftPrimaryJoystick( new Joystick(1) ),
	rightPrimaryJoystick( new Joystick(2) ),
	secondaryJoystick( new Joystick(3) ),
	
	oneTenthSpeedMultiplierButton( new JoystickButton( leftPrimaryJoystick, 2) ),
	halfSpeedMultiplierButton( new JoystickButton( leftPrimaryJoystick, 1) ),
	fullSpeedButton( new JoystickButton( rightPrimaryJoystick, 1) ),
	halfSpeedTurningMultiplierButton( new JoystickButton( rightPrimaryJoystick, 3) ),
	quarterSpeedTurningMultiplierButton( new JoystickButton( rightPrimaryJoystick, 5) ),
	
	fireButton( new JoystickButton(secondaryJoystick, 1) ),
	setpointOneButton( new JoystickButton(secondaryJoystick, 3) ),
	setpointTwoButton( new JoystickButton(secondaryJoystick, 4) ),
	setpointThreeButton( new JoystickButton(secondaryJoystick, 5) ){
	fireButton->WhenPressed(new Shoot());
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

bool OI::getOneTenthSpeedMultiplierButtonValue() {
	return oneTenthSpeedMultiplierButton->Get();
}

bool OI::getHalfSpeedMultiplierButtonValue() {
	return halfSpeedMultiplierButton->Get();
}

bool OI::getFullSpeedButtonValue() {
	return fullSpeedButton->Get();
}

bool OI::getHalfSpeedTurningMultiplierButtonValue() {
	return halfSpeedTurningMultiplierButton->Get();
}


bool OI::getQuarterSpeedTurningMultiplierButtonValue() {
	return quarterSpeedTurningMultiplierButton->Get();
}

bool OI::getFireButtonValue() {
	return fireButton->Get();
}

bool OI::getSetpointOneButtonValue() {
	return setpointOneButton->Get();
}

bool OI::getSetpointTwoButtonValue() {
	return setpointTwoButton->Get();
}

bool OI::getSetpointThreeButtonValue() {
	return setpointThreeButton->Get();
}
