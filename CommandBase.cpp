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

Shooter* CommandBase::shooter = 0;
Drive* CommandBase::drive = 0;
ShooterArticulator* CommandBase::shooterArticulator = 0;
CompressorSystem* CommandBase::compressorSystem = 0;
OI* CommandBase::operatorInterface = 0;

/**
 * Initialize the subsystems
 *
 * @author Nyle Rodgers
 * @author William Kunkel
 */
void CommandBase::init() {
	shooter = new Shooter();
	drive = new Drive();
	shooterArticulator = new ShooterArticulator();
	compressorSystem = new CompressorSystem();
	operatorInterface = new OI();
}
