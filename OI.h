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
	
	/// Get the one tenth speed multiplier button state
	bool getOneTenthSpeedMultiplierButtonValue();
	
	/// Get the half speed multiplier button state
	bool getHalfSpeedMultiplierButtonValue();
	
	/// Get the full speed button state
	bool getFullSpeedButtonValue();
	
	/// Get the half speed turning multiplier button state
	bool getHalfSpeedTurningMultiplierButtonValue();
	
	/// Get the quarter speed turning multiplier button state
	bool getQuarterSpeedTurningMultiplierButtonValue();
	
	/// Get the drive spin around left button state
	bool getSpinAroundLeftButtonValue();
	
	/// Get the drive spin around right button state
	bool getSpinAroundRightButtonValue();
	
	/// Get the toggle climber button state
	bool getToggleClimberButtonValue();
	
	/// Get the fire button state
	bool getFireButtonValue();
	
	/// Get the setpoint zero button state
	bool getSetpointZeroButtonValue();
	
	/// Get the setpoint one button state
	bool getSetpointOneButtonValue();
	
	/// Get the setpoint two button state
	bool getSetpointTwoButtonValue();
	
	/// Get the setpoint three button state
	bool getSetpointThreeButtonValue();
	
private:
	Joystick *leftPrimaryJoystick,
	         *rightPrimaryJoystick,
	         *secondaryJoystick;
	JoystickButton // primary driver buttons
	               *oneTenthSpeedMultiplierButton,
	               *halfSpeedMultiplierButton,
	               *fullSpeedButton,
	               *halfSpeedTurningMultiplierButton,
	               *quarterSpeedTurningMultiplierButton,
	               *spinAroundLeftButton,
	               *spinAroundRightButton,
	               
	               *toggleClimberButton,
	               
	               // secondary driver buttons
	               *fireButton,
	               
	               *setpointZeroButton,
	               *setpointOneButton,
	               *setpointTwoButton,
	               *setpointThreeButton;
};

#endif // OI_H
