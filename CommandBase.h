/**
 * @file CommandBase.h
 * @brief Decleration of the command base
 * @author Nyle Rodgers
 * @author William Kunkel 
 */

#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Commands/Command.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Drive.h"
#include "OI.h"


/**
 * @brief The base for all commands
 *
 * Provides a common base which all commands can use to access each subsystem as
 * well as the operator interface.
 *
 * @author William Kunkel
 * @author Nyle Rodgers
 */
class CommandBase: public Command {
public:
	/// Provides a fall-through to the Command constructor
	CommandBase(const char *name);

	/// Set up the subsystems
	static void init();

protected:
	/// The robot's Shooter
	static Shooter *shooter;
	/// The robot's Drive
	static Drive *drive;
	/// The operator interface for the robot
	static OI *oi;
};

#endif // COMMAND_BASE_H
