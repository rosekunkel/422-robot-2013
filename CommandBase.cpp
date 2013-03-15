/**
* @file CommandBase.cpp
* @brief Implementation of the command base
* @author Nyle Rodgers
* @author William Kunkel
*/

#include "CommandBase.h"
#include "Commands/Scheduler.h"

/**
 * A constructor for command base
 *
 * @author Nyle Rodgers
 */
CommandBase::CommandBase(const char *name) : Command(name) {
}

/**
 * A constructor for command base
 *
 * @author Nyle Rodgers
 */
CommandBase::CommandBase() : Command() {
}

Climber* CommandBase::climber = 0;
CompressorSystem* CommandBase::compressorSystem = 0;
Drive* CommandBase::drive = 0;
Pusher* CommandBase::pusher = 0;
Shooter* CommandBase::shooter = 0;
#ifdef USE_PISTON_ARTICULATOR
PistonArticulator* CommandBase::pistonArticulator = 0;
#else
ShooterArticulator* CommandBase::shooterArticulator = 0;
#endif
Lights* CommandBase::lights = 0;
VariableDial* CommandBase::variableDial = 0;
Antennae* CommandBase::antennae = 0;
NuclearOption* CommandBase::nuclearOption = 0;
Flashlight* CommandBase::flashlight = 0;
OI* CommandBase::operatorInterface = 0;

/**
 * Initialize the subsystems
 *
 * @author Nyle Rodgers
 * @author William Kunkel
 */
void CommandBase::init() {
	climber = new Climber();
	compressorSystem = new CompressorSystem();
	drive = new Drive();
	pusher = new Pusher();
	shooter = new Shooter();
#ifdef USE_PISTON_ARTICULATOR
	pistonArticulator = new PistonArticulator();
#else
	shooterArticulator = new ShooterArticulator();
#endif
	lights = new Lights();
	variableDial = new VariableDial();
	antennae = new Antennae();
	nuclearOption = new NuclearOption();
	flashlight = new Flashlight();
	operatorInterface = new OI();
}
