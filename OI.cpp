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
#include "Commands/ToggleFlashlight.h"

#ifndef USE_PISTON_ARTICULATOR
#include "Commands/SetShooterArticulator.h"
#else
#ifdef PRIMARY_CONTROLS_ARTICULATOR
#include "Commands/ToggleArticulator.h"
#endif
#endif

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
	lowSpeedButton( new JoystickButton( primaryJoystick, PS3_SQUARE ) ),
   	halfSpeedButton( new JoystickButton( primaryJoystick, PS3_TRIANGLE ) ),
	fullSpeedButton( new JoystickButton( primaryJoystick, PS3_CIRCLE ) ),

	quarterTurnSpeedButton( new JoystickButton( primaryJoystick, PS3_LEFT ) ),
	halfTurnSpeedButton( new JoystickButton( primaryJoystick, PS3_UP ) ),
	fullTurnSpeedButton( new JoystickButton( primaryJoystick, PS3_RIGHT ) ),
	
	turn180Button( new JoystickButton( primaryJoystick, PS3_R1 ) ),
	toggleClimberButton( new JoystickButton( primaryJoystick, PS3_L1 ) ),
#else
	lowSpeedButton( new JoystickButton( leftPrimaryJoystick, 2 ) ),
   	halfSpeedButton( new JoystickButton( leftPrimaryJoystick, 1 ) ),
	fullSpeedButton( new JoystickButton( rightPrimaryJoystick, 1 ) ),

	quarterTurnSpeedButton( new JoystickButton( rightPrimaryJoystick, 4 ) ),
	halfTurnSpeedButton( new JoystickButton( rightPrimaryJoystick, 3 ) ),
	fullTurnSpeedButton( new JoystickButton( rightPrimaryJoystick, 5 ) ),
	
	turn180Button( new JoystickButton( rightPrimaryJoystick, 2 ) ),
	toggleClimberButton( new JoystickButton( rightPrimaryJoystick, 10 ) ),

#ifdef USE_PISTON_ARTICULATOR
#ifdef PRIMARY_CONTROLS_ARTICULATOR
	toggleArticulatorButton( new JoystickButton( leftPrimaryJoystick, 7) ),
#endif
#endif
	
#endif
	
	// Secondary driver controls
#ifdef USE_GAMECUBE_CONTROLLER
	fireButton( new JoystickButton( secondaryJoystick, GC_A ) ),

	stopShooterButton( new JoystickButton( secondaryJoystick, GC_B )),
	lowSetpointButton( new JoystickButton( secondaryJoystick, GC_LEFT ) ),
	midSetpointButton( new JoystickButton( secondaryJoystick, GC_UP ) ),
	highSetpointButton( new JoystickButton( secondaryJoystick, GC_RIGHT ) ),
	increaseSetpointButton( new JoystickButton( secondaryJoystick, GC_Y) ),
	decreaseSetpointButton( new JoystickButton( secondaryJoystick, GC_X) ),

	toggleRedButton( new JoystickButton( secondaryJoystick, GC_L ) ),
	toggleBlueButton( new JoystickButton( secondaryJoystick, GC_R ) ),
	
	toggleFlashlightButton( new JoystickButton( secondaryJoystick, GC_Z ) ),

	liftResetButton( new JoystickButton( secondaryJoystick, 0 ) )
#else
	fireButton( new JoystickButton( secondaryJoystick, 1 ) ),

	stopShooterButton( new JoystickButton( secondaryJoystick, 2 )),
	lowSetpointButton( new JoystickButton( secondaryJoystick, 4 ) ),
	midSetpointButton( new JoystickButton( secondaryJoystick, 3 ) ),
	highSetpointButton( new JoystickButton( secondaryJoystick, 5 ) ),
	increaseSetpointButton( new JoystickButton( secondaryJoystick, 11) ),
	decreaseSetpointButton( new JoystickButton( secondaryJoystick, 10) ),
	
	toggleRedButton( new JoystickButton( secondaryJoystick, 6 ) ),
	toggleBlueButton( new JoystickButton( secondaryJoystick, 7 ) ),
	
	toggleFlashlightButton( new JoystickButton( secondaryJoystick, 0 ) ),
	
	liftResetButton( new JoystickButton( secondaryJoystick, 0 ) )
#endif
{
	toggleClimberButton->WhenPressed( new ToggleClimber() );

#ifdef USE_PISTON_ARTICULATOR
#ifdef PRIMARY_CONTROLS_ARTICULATOR
	toggleArticulatorButton->WhenPressed( new ToggleArticulator() );
#endif
#endif
	
	turn180Button->WhenPressed( new SpinHalfRotation() );
	
	toggleRedButton->WhenPressed( new ControlLights(ControlLights::RED) );
	toggleBlueButton->WhenPressed( new ControlLights(ControlLights::BLUE) );

	fireButton->WhenPressed( new Shoot() );
	
	toggleFlashlightButton->WhenPressed( new ToggleFlashlight() );
	
#ifndef USE_PISTON_ARTICULATOR
	liftResetButton->WhenPressed( new SetShooterArticulator( 0.0 ) );
#endif
}
