/**
 * @file Shooter.cpp
 * @brief Definition of the start shooter pusher command
 * @author Nyle Rodgers
 * @author William Kunkel
 */

#ifndef START_HOPPER_WHEEL_H
#define START_HOPPER_WHEEL_H

#include "../CommandBase.h"

/**
 * @brief Starts the hopper pusher wheel motor
 *
 * Run the motor for the spring-loaded wheel on the hopper, at top speed.
 *
 * @note This motor is run continuously from the beginning of the match.
 *
 * @author Nyle Rodgers
 * @author William Kunkel
 */
class StartHopperWheel: public CommandBase {
public:
	/// Constructor for the StartHopperWheel command
	StartHopperWheel();

	/// Code to run when the command is started
	void Initialize();

	/// Return true
	bool IsFinished();

	/// Empty method, everything happens in initialization
	void Execute() {};

	/// No special handling for the end of the command
	void End() {};

	/// Nothing to do when interrupted
	void Interrupted() {};
};

#endif // START_HOPPER_WHEEL_H
