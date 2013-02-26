/**
 * @file OI.cpp
 * @brief Implementation of the Operater Interface
 * @author Nyle Rodgers
 */

#include "OI.h"
#include "Commands/Shoot.h"
#include "Commands/ToggleClimber.h"
#include "Commands/ControlLights.h"

/**
 * Initilize the Operator Interface.
 *
 * @author Nyle Rodgers
 */
OI::OI():
	// Joysticks
	leftPrimaryJoystick( new Joystick(1) ),
	rightPrimaryJoystick( new Joystick(2) ),
	secondaryJoystick( new Joystick(3) ),
	
	// Primary
	oneTenthSpeedMultiplierButton( new JoystickButton( leftPrimaryJoystick, 2 ) ),
	halfSpeedMultiplierButton( new JoystickButton( leftPrimaryJoystick, 1 ) ),
	fullSpeedButton( new JoystickButton( rightPrimaryJoystick, 1 ) ),
	
	halfSpeedTurningMultiplierButton( new JoystickButton( rightPrimaryJoystick, 5 ) ),
	quarterSpeedTurningMultiplierButton( new JoystickButton( rightPrimaryJoystick, 4 ) ),
	
	driveReverseButton( new JoystickButton( leftPrimaryJoystick, 3 ) ),
	
	toggleClimberButton( new JoystickButton( rightPrimaryJoystick, 7 ) ),
	
	// Secondary
	
	fireButton( new JoystickButton( secondaryJoystick, 1 ) ),
	setpointZeroButton( new JoystickButton ( secondaryJoystick, 2 )),
	setpointOneButton( new JoystickButton( secondaryJoystick, 4 ) ),
	setpointTwoButton( new JoystickButton( secondaryJoystick, 3 ) ),
	toggleRedButton( new JoystickButton ( secondaryJoystick, 6)),
    toggleBlueButton( new JoystickButton (secondaryJoystick, 7)),
	toggleGreenButton( new JoystickButton (secondaryJoystick, 8)),
	setpointThreeButton( new JoystickButton( secondaryJoystick, 5 ) ) {
	toggleClimberButton->WhenPressed( new ToggleClimber() );
	toggleRedButton->WhenPressed( new ControlLights(0) );
	toggleBlueButton->WhenPressed( new ControlLights(1) );
	toggleGreenButton->WhenPressed( new ControlLights(2) );
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

/**
 * Get the one tenth speed multiplier button state.
 *
 * @author Nyle Rodgers
 */
bool OI::getOneTenthSpeedMultiplierButtonValue() {
	return oneTenthSpeedMultiplierButton->Get();
}

/**
 * Get the half speed multiplier button state.
 *
 * @author Nyle Rodgers
 */
bool OI::getHalfSpeedMultiplierButtonValue() {
	return halfSpeedMultiplierButton->Get();
}

/**
 * Get the full speed multiplier button state.
 *
 * @author Nyle Rodgers
 */
bool OI::getFullSpeedButtonValue() {
	return fullSpeedButton->Get();
}

/**
 * Get the half speed turning multiplier button state.
 *
 * @author Nyle Rodgers
 */
bool OI::getHalfSpeedTurningMultiplierButtonValue() {
	return halfSpeedTurningMultiplierButton->Get();
}

/**
 * Get the quarter speed turning multiplier button state.
 *
 * @author Nyle Rodgers
 */
bool OI::getQuarterSpeedTurningMultiplierButtonValue() {
	return quarterSpeedTurningMultiplierButton->Get();
}

/**
 * Get the drive reverse button state.
 *
 * @author Nyle Rodgers
 */
bool OI::getDriveReverseButtonValue() {
	return driveReverseButton->Get();
}

/**
 * Get the toggle climber button state.
 *
 * @author Nyle Rodgers
 */
bool OI::getToggleClimberButtonValue() {
	return toggleClimberButton->Get();
}

/**
 * Get the half speed turning multiplier button state.
 *
 * @author Nyle Rodgers
 */
bool OI::getFireButtonValue() {
	return fireButton->Get();
}

bool OI::getSetpointZeroButtonValue() {
	return setpointZeroButton->Get();
}

/**
 * Get the setpoint one button state.
 *
 * @author Nyle Rodgers
 */
bool OI::getSetpointOneButtonValue() {
	return setpointOneButton->Get();
}

/**
 * Get the setpoint two button state.
 *
 * @author Nyle Rodgers
 */
bool OI::getSetpointTwoButtonValue() {
	return setpointTwoButton->Get();
}

/**
 * Get the setpoint three button state.
 *
 * @author Nyle Rodgers
 */
bool OI::getSetpointThreeButtonValue() {
	return setpointThreeButton->Get();
}


/**
 * Color States
 *
 * @author Lucario
 */
bool OI::getToggleRedButtonValue() {
	return toggleRedButton->Get();
}
bool OI::getToggleBlueButtonValue() {
	return toggleBlueButton->Get();
}
bool OI::getToggleGreenButtonValue() {
	return toggleGreenButton->Get();
}
