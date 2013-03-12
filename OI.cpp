/**
 * @file OI.cpp
 * @brief Implementation of the Operater Interface
 * @author Nyle Rodgers
 */

#include "OI.h"
#include "Commands/Shoot.h"
#include "Commands/RaiseClimber.h"
#include "Commands/ToggleClimber.h"
#include "Commands/SpinHalfRotation.h"
#include "Commands/ControlLights.h"

/**
 * Initilize the Operator Interface.
 *
 * @author Nyle Rodgers
 */
OI::OI():
	// Joysticks
#ifdef USE_PS3_CONTROLLER
	primaryJoystick( new Joystick(1) ),
#else
	leftPrimaryJoystick( new Joystick(1) ),
	rightPrimaryJoystick( new Joystick(2) ),
#endif
	secondaryJoystick( new Joystick(3) ),
	
	// Primary
#ifdef USE_PS3_CONTROLLER
	// TODO: Get actual buttons mapped for the PS3 controller
	oneTenthSpeedMultiplierButton(
   	   new JoystickButton( primaryJoystick, 0 ) ),
	halfSpeedMultiplierButton(
		new JoystickButton( primaryJoystick, 0 ) ),
	fullSpeedButton(
		new JoystickButton( primaryJoystick, 0 ) ),

	halfSpeedTurningMultiplierButton(
		new JoystickButton( primaryJoystick, 0 ) ),
	quarterSpeedTurningMultiplierButton(
		new JoystickButton( primaryJoystick, 0 ) ),
	
	driveReverseButton( new JoystickButton( primaryJoystick, 0 ) ),
	stopDriveButton( new JoystickButton( primaryJoystick, 0 ) ),
	
	raiseClimberButton( new JoystickButton( primaryJoystick, 0 ) ),
#else
	oneTenthSpeedMultiplierButton(
   	   new JoystickButton( leftPrimaryJoystick, 2 ) ),
	halfSpeedMultiplierButton(
		new JoystickButton( leftPrimaryJoystick, 1 ) ),
	fullSpeedButton(
		new JoystickButton( rightPrimaryJoystick, 1 ) ),

	halfSpeedTurningMultiplierButton(
		new JoystickButton( rightPrimaryJoystick, 5 ) ),
	quarterSpeedTurningMultiplierButton(
		new JoystickButton( rightPrimaryJoystick, 4 ) ),
	
	driveReverseButton( new JoystickButton( leftPrimaryJoystick, 3 ) ),
	stopDriveButton( new JoystickButton( leftPrimaryJoystick, 3 ) ),
	
	raiseClimberButton( new JoystickButton( rightPrimaryJoystick, 2 ) ),
#endif
	
	// Secondary for Joysticks
#ifdef USE_GAMECUBE_CONTROLLER
	fireButton( new JoystickButton( secondaryJoystick, 1 ) ),

	setpointZeroButton( new JoystickButton ( secondaryJoystick, 2 )),
	setpointOneButton( new JoystickButton( secondaryJoystick, 9 ) ),
	setpointTwoButton( new JoystickButton( secondaryJoystick, 12 ) ),
	setpointThreeButton( new JoystickButton( secondaryJoystick, 10 ) ),

	toggleRedButton( new JoystickButton ( secondaryJoystick, 5)),
    toggleGreenButton( new JoystickButton (secondaryJoystick, 6)),
	toggleBlueButton( new JoystickButton (secondaryJoystick, 7))
#else
	fireButton( new JoystickButton( secondaryJoystick, 1 ) ),

	setpointZeroButton( new JoystickButton ( secondaryJoystick, 2 )),
	setpointOneButton( new JoystickButton( secondaryJoystick, 4 ) ),
	setpointTwoButton( new JoystickButton( secondaryJoystick, 3 ) ),
	setpointThreeButton( new JoystickButton( secondaryJoystick, 5 ) ),

	toggleRedButton( new JoystickButton ( secondaryJoystick, 6)),
    toggleGreenButton( new JoystickButton (secondaryJoystick, 7)),
	toggleBlueButton( new JoystickButton (secondaryJoystick, 8))
#endif
{
	raiseClimberButton->WhenPressed( new ToggleClimber() );
	toggleRedButton->WhenPressed( new ControlLights(0) );
	toggleGreenButton->WhenPressed( new ControlLights(1) );
	toggleBlueButton->WhenPressed( new ControlLights(2) );

	fireButton->WhenPressed(new Shoot());
}

#ifdef USE_PS3_CONTROLLER
Joystick* OI::getPrimaryJoystick() {
	return primaryJoystick;
}
#else
Joystick* OI::getLeftPrimaryJoystick() {
	return leftPrimaryJoystick;
}

Joystick* OI::getRightPrimaryJoystick() {
	return rightPrimaryJoystick;
}
#endif

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

bool OI::getDriveReverseButtonValue() {
	return driveReverseButton->Get();
}

bool OI::getStopDriveButtonValue() {
	return stopDriveButton->Get();
}

bool OI::getRaiseClimberButtonValue() {
	return raiseClimberButton->Get();
}

bool OI::getFireButtonValue() {
	return fireButton->Get();
}

bool OI::getSetpointZeroButtonValue() {
	return setpointZeroButton->Get();
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

bool OI::getToggleRedButtonValue() {
	return toggleRedButton->Get();
}
bool OI::getToggleBlueButtonValue() {
	return toggleBlueButton->Get();
}
bool OI::getToggleGreenButtonValue() {
	return toggleGreenButton->Get();
}
