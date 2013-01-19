/**
* @file CommandBase.h
* @brief Decleration of the command base
* @author Nyle Rodgers
*/

#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Commands/StartShooterPusher.h"
#include "Subsystems/Shooter.h"
#include "OI.h"


/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 * 
 */
class CommandBase: public Command {
public:
	CommandBase(const char *name);
	CommandBase();
	static void init();
	static Shooter *shoter;
	static OI *oi;
};

#endif
