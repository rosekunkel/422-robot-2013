/**
 * @file OI.cpp
 * @brief Implementation of the Operater Interface
 * @author Nyle Rodgers
 */

#include "OI.h"
#include "Commands/Shoot.h"
#include "Commands/ToggleClimber.h"
#include "Commands/SpinHalfRotation.h"
#include "Commands/ControlLights.h"
#include "RobotMap.h"

/**
 * Initilize the Operator Interface.
 *
 * @author Nyle Rodgers
 * @author William Kunkel
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
	
	// Primary driver controls
#ifdef USE_PS3_CONTROLLER
	tenthSpeedButton( new JoystickButton( primaryJoystick, PS3_SQUARE ) ),
   	halfSpeedButton( new JoystickButton( primaryJoystick, PS3_TRIANGLE ) ),
	fullSpeedButton( new JoystickButton( primaryJoystick, PS3_CIRCLE ) ),

	quarterTurnSpeedButton( new JoystickButton( primaryJoystick, PS3_LEFT ) ),
	halfTurnSpeedButton( new JoystickButton( primaryJoystick, PS3_UP ) ),
	fullTurnSpeedButton( new JoystickButton( primaryJoystick, PS3_RIGHT ) ),
	
	turn180Button( new JoystickButton( primaryJoystick, PS3_R1 ) ),
	toggleClimberButton( new JoystickButton( primaryJoystick, PS3_L1 ) ),
#else
	tenthSpeedButton( new JoystickButton( leftPrimaryJoystick, 2 ) ),
   	halfSpeedButton( new JoystickButton( leftPrimaryJoystick, 1 ) ),
	fullSpeedButton( new JoystickButton( rightPrimaryJoystick, 1 ) ),

	// TODO: Get a button mapped for the full-speed turning multiplier
	quarterTurnSpeedButton( new JoystickButton( rightPrimaryJoystick, 4 ) ),
	halfTurnSpeedButton( new JoystickButton( rightPrimaryJoystick, 5 ) ),
	fullTurnSpeedButton( new JoystickButton( leftPrimaryJoystick, 1 ) ),
	
	// TODO: Get a button mapped for the 180 turn
	turn180Button( new JoystickButton( leftPrimaryJoystick, 1 ) ),
	toggleClimberButton( new JoystickButton( rightPrimaryJoystick, 2 ) ),
#endif
	
	// Secondary driver controls
#ifdef USE_GAMECUBE_CONTROLLER
	fireButton( new JoystickButton( secondaryJoystick, GC_A ) ),

	stopShooterButton( new JoystickButton( secondaryJoystick, GC_B )),
	lowSetpointButton( new JoystickButton( secondaryJoystick, GC_LEFT ) ),
	midSetpointButton( new JoystickButton( secondaryJoystick, GC_UP ) ),
	highSetpointButton( new JoystickButton( secondaryJoystick, GC_RIGHT ) ),

	toggleRedButton( new JoystickButton( secondaryJoystick, GC_L ) ),
    toggleGreenButton( new JoystickButton(secondaryJoystick, GC_R ) ),
	toggleBlueButton( new JoystickButton(secondaryJoystick, GC_Z ) )
#else
	fireButton( new JoystickButton( secondaryJoystick, 1 ) ),

	stopShooterButton( new JoystickButton( secondaryJoystick, 2 )),
	lowSetpointButton( new JoystickButton( secondaryJoystick, 4 ) ),
	midSetpointButton( new JoystickButton( secondaryJoystick, 3 ) ),
	highSetpointButton( new JoystickButton( secondaryJoystick, 5 ) ),

	toggleRedButton( new JoystickButton( secondaryJoystick, 6 ) ),
    toggleGreenButton( new JoystickButton(secondaryJoystick, 7 ) ),
	toggleBlueButton( new JoystickButton(secondaryJoystick, 8 ) )
#endif
{
	toggleClimberButton->WhenPressed( new ToggleClimber() );
	turn180Button->WhenPressed( new SpinHalfRotation() );
	
	toggleRedButton->WhenPressed( new ControlLights(ControlLights::RED) );
	toggleGreenButton->WhenPressed( new ControlLights(ControlLights::GREEN) );
	toggleBlueButton->WhenPressed( new ControlLights(ControlLights::BLUE) );

	fireButton->WhenPressed( new Shoot() );
}
