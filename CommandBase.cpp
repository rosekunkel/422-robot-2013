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
ShooterArticulator* CommandBase::shooterArticulator = 0;
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
	shooterArticulator = new ShooterArticulator();
	operatorInterface = new OI();
}
