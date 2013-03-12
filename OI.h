/**
 * @file OI.h
 * @brief Declaration of the Operator Interface
 * @author Nyle Rodgers
 */

#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "CompilationSettings.h"

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

#ifdef USE_PS3_CONTROLLER
	/// Get the controller for the primary driver
	Joystick* getPrimaryJoystick();
#else
	/// Get the left Joystick for the primary driver
	Joystick* getLeftPrimaryJoystick();
	
	/// Get the right Joystick for the primary driver
	Joystick* getRightPrimaryJoystick();
#endif
	
	/// Get the joystick for the secondary driver
	Joystick* getSecondaryJoystick();
	
	
	bool getOneTenthSpeedMultiplierButtonValue();
	bool getHalfSpeedMultiplierButtonValue();
	bool getFullSpeedButtonValue();
	
	bool getHalfSpeedTurningMultiplierButtonValue();
	bool getQuarterSpeedTurningMultiplierButtonValue();
	
	bool getDriveReverseButtonValue();
	bool getStopDriveButtonValue();
	
	bool getRaiseClimberButtonValue();
	bool getFireButtonValue();
	
	bool getSetpointZeroButtonValue();
	bool getSetpointOneButtonValue();
	bool getSetpointTwoButtonValue();
	bool getSetpointThreeButtonValue();

	/// Get LED Button states
	bool getToggleRedButtonValue();
	bool getToggleGreenButtonValue();
	bool getToggleBlueButtonValue();
	
private:
	
#ifdef USE_PS3_CONTROLLER
	Joystick *primaryJoystick;
#else
	Joystick *leftPrimaryJoystick,
	         *rightPrimaryJoystick;
#endif
	
	Joystick *secondaryJoystick;

	               // Primary driver buttons
	JoystickButton *oneTenthSpeedMultiplierButton,
	               *halfSpeedMultiplierButton,
	               *fullSpeedButton,

	               *halfSpeedTurningMultiplierButton,
	               *quarterSpeedTurningMultiplierButton,

	               *driveReverseButton,
	               *stopDriveButton,

	               *raiseClimberButton,
	               
	               // Secondary driver buttons
	               *fireButton,

	               *setpointZeroButton,
	               *setpointOneButton,
	               *setpointTwoButton,
	               *setpointThreeButton,

                   *toggleRedButton,
				   *toggleGreenButton,
				   *toggleBlueButton;
};

#endif // OI_H
