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
	
	/// Get the one tenth speed multiplier button
	bool getOneTenthSpeedMultiplierButtonValue();
	
	/// Get the half speed multiplier button
	bool getHalfSpeedMultiplierButtonValue();
	
	/// Get the full speed button
	bool getFullSpeedButtonValue();
	
	/// Get the half speed turning multiplier button
	bool getHalfSpeedTurningMultiplierButtonValue();
	
	/// Get the quarter speed turning multiplier button
	bool getQuarterSpeedTurningMultiplierButtonValue();
	
	/// Get the fire button
	bool getFireButtonValue();
	
	/// Get the setpoint one button
	bool getSetpointOneButtonValue();
	
	/// Get the setpoint two button
	bool getSetpointTwoButtonValue();
	
	/// Get the setpoint three button
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
	               // secondary driver buttons
	               *fireButton,
	               *setpointOneButton,
	               *setpointTwoButton,
	               *setpointThreeButton;
};

#endif // OI_H
