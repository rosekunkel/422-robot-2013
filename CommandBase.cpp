/**
* @file CommandBase.cpp
* @brief Implementation of the Shooter subsystem
* @author Nyle Rodgers
*/

#include "CommandBase.h"
#include "Subsystems/Shooter.h"
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

Shooter* CommandBase::shooter = NULL;
OI* CommandBase::oi = NULL;

/**
 * Initialize the subsystems
 *
 * @author Nyle Rodgers
 */
void CommandBase::init() {
	shooter = new Shooter();
	oi = new OI();
}
