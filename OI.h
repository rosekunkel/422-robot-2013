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
	Joystick* getPrimaryJoystick() { return primaryJoystick; }
#else
	Joystick* getLeftPrimaryJoystick() { return leftPrimaryJoystick; }

	Joystick* getRightPrimaryJoystick() { return rightPrimaryJoystick; }
#endif

	Joystick* getSecondaryJoystick() { return secondaryJoystick; }
	
	bool lowSpeedButtonPressed() { return lowSpeedButton->Get(); }
	bool halfSpeedButtonPressed() { return halfSpeedButton->Get(); }
	bool fullSpeedButtonPressed() { return fullSpeedButton->Get(); }
	
	// TODO: Resolve line below not being <= 80 columns
	bool quarterTurnSpeedButtonPressed() { return quarterTurnSpeedButton->Get(); }
	bool halfTurnSpeedButtonPressed() { return halfTurnSpeedButton->Get(); }
	bool fullTurnSpeedButtonPressed() { return fullTurnSpeedButton->Get(); }
	
	bool turn180ButtonPressed() { return turn180Button->Get(); }
	bool toggleClimberButtonPressed() { return toggleClimberButton->Get(); }
	
#ifdef USE_PISTON_ARTICULATOR
#ifdef PRIMARY_CONTROLS_ARTICULATOR
	bool toggleArticulatorButtonPressed() { return toggleArticulatorButton->Get(); }
#endif
#endif
	
	bool fireButtonPressed() { return fireButton->Get(); }
	
	bool stopShooterButtonPressed() { return stopShooterButton->Get(); }
	bool lowSetpointButtonPressed() { return lowSetpointButton->Get(); }
	bool midSetpointButtonPressed() { return midSetpointButton->Get(); }
	bool highSetpointButtonPressed() { return highSetpointButton->Get(); }
	// TODO: Resolve lines below not being <= 80 columns
	bool increaseSetpointButtonPressed() { return increaseSetpointButton->Get(); }
	bool decreaseSetpointButtonPressed() { return decreaseSetpointButton->Get(); }

	// Underglow controls
	bool toggleRedButtonPressed() { return toggleRedButton->Get(); }
	bool toggleBlueButtonPressed() { return toggleBlueButton->Get(); }
	
	bool toggleFlashlightButtonPressed() { return toggleFlashlightButton->Get(); }
	
	bool liftResetButtonPressed() { return liftResetButton->Get(); }
private:
	
#ifdef USE_PS3_CONTROLLER
	Joystick *primaryJoystick;
#else
	Joystick *leftPrimaryJoystick,
	         *rightPrimaryJoystick;
#endif
	
	Joystick *secondaryJoystick;

	               // Primary driver buttons
	JoystickButton *lowSpeedButton,
	               *halfSpeedButton,
	               *fullSpeedButton,
	               
	               *quarterTurnSpeedButton,
	               *halfTurnSpeedButton,
	               *fullTurnSpeedButton,

	               *turn180Button,
	               *toggleClimberButton,

#ifdef USE_PISTON_ARTICULATOR
#ifdef PRIMARY_CONTROLS_ARTICULATOR
	               *toggleArticulatorButton,
#endif
#endif
	               
	               // Secondary driver buttons
	               *fireButton,

	               *stopShooterButton,
	               *lowSetpointButton,
	               *midSetpointButton,
	               *highSetpointButton,
	               
	               *increaseSetpointButton,
	               *decreaseSetpointButton,

                   *toggleRedButton,
				   *toggleBlueButton,

				   *toggleFlashlightButton,
				   *liftResetButton;
};

#endif // OI_H
