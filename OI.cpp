/**
 * @file OI.cpp
 * @brief Implementation of the Operater Interface
 * @author Nyle Rodgers
 */

#include "OI.h"
#include "Commands/Shoot.h"
#include "Commands/RaiseClimber.h"
#include "Commands/SpinHalfRotation.h"

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
	
	spinAroundLeftButton( new JoystickButton( leftPrimaryJoystick, 4 ) ),
	spinAroundRightButton( new JoystickButton( leftPrimaryJoystick, 5 ) ),
	
	stopDriveButton( new JoystickButton( leftPrimaryJoystick, 3 ) ),
	
	raiseClimberButton( new JoystickButton( rightPrimaryJoystick, 2 ) ),
	
	// Secondary
	
	fireButton( new JoystickButton( secondaryJoystick, 1 ) ),
	setpointZeroButton( new JoystickButton ( secondaryJoystick, 2 )),
	setpointOneButton( new JoystickButton( secondaryJoystick, 4 ) ),
	setpointTwoButton( new JoystickButton( secondaryJoystick, 3 ) ),
	setpointThreeButton( new JoystickButton( secondaryJoystick, 5 ) ) {
	
	raiseClimberButton->WhenPressed( new RaiseClimber() );
	
	fireButton->WhenPressed(new Shoot());
	
	spinAroundLeftButton->WhenPressed( new SpinHalfRotation( true ) );
	spinAroundRightButton->WhenPressed( new SpinHalfRotation( false ) );
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
 * Get the spin around left button state.
 *
 * @author Nyle Rodgers
 */
bool OI::getSpinAroundLeftButtonValue() {
	return spinAroundLeftButton->Get();
}

/**
 * Get the spin around right button state.
 *
 * @author Nyle Rodgers
 */
bool OI::getSpinAroundRightButtonValue() {
	return spinAroundRightButton->Get();
}

/**
 * Get the stop drive button state.
 *
 * @author Nyle Rodgers
 */
bool OI::getStopDriveButtonValue() {
	return stopDriveButton->Get();
}

/**
 * Get the toggle climber button state.
 *
 * @author Nyle Rodgers
 */
bool OI::getRaiseClimberButtonValue() {
	return raiseClimberButton->Get();
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
