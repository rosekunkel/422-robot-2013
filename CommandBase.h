/**
 * @file CommandBase.h
 * @brief Decleration of the command base
 * @author Nyle Rodgers
 * @author William Kunkel 
 */

#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "CompilationSettings.h"

#include "Commands/Command.h"
#include "Subsystems/Climber.h"
#include "Subsystems/CompressorSystem.h"
#include "Subsystems/Drive.h"
#include "Subsystems/Pusher.h"
#include "Subsystems/Shooter.h"
#ifdef USE_PISTON_ARTICULATOR
#include "Subsystems/PistonArticulator.h"
#else
#include "Subsystems/ShooterArticulator.h"
#endif
#include "Subsystems/Lights.h"
#include "Subsystems/VariableDial.h"
#include "Subsystems/Antennae.h"
#include "Subsystems/NuclearOption.h"
#include "Subsystems/Flashlight.h"
#include "OI.h"


/**
 * @brief The base for all commands
 *
 * Provides a common base which all commands can use to access each subsystem 
 * as well as the operator interface.
 *
 * @author William Kunkel
 * @author Nyle Rodgers
 */
class CommandBase: public Command {
public:
	/// Provides a fall-through to the Command constructor
	CommandBase(const char *name);
	/// Provides a fall-through to the Command constructor
	CommandBase();
	/// Set up the subsystems
	static void init();

protected:
	/// The robot's Climber
	static Climber *climber;
	/// The robot's compressor
	static CompressorSystem *compressorSystem;
	/// The robot's Drive
	static Drive *drive;
	/// The robot's disk pusher
	static Pusher *pusher;
	/// The robot's Shooter
	static Shooter *shooter;
	/// The robot's Shooter Articulator
#ifdef USE_PISTON_ARTICULATOR
	static PistonArticulator *pistonArticulator;
#else
	static ShooterArticulator *shooterArticulator;
#endif
	/// The robot's LED's
	static Lights *lights;
	/// The dial used to delay autonomous
	static VariableDial *variableDial;
	/// The sensor antennae
	static Antennae *antennae;
	static NuclearOption *nuclearOption;
	static Flashlight *flashlight;
	/// The operator interface for the robot
	static OI *operatorInterface;
};

#endif // COMMAND_BASE_H
