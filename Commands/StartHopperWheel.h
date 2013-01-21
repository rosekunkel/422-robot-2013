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
 * This should be run at the beginning of the match
 *
 * @author Nyle Rodgers
 * @author William Kunkel
 */
class StartHopperWheel: public CommandBase {
public:
	StartHopperWheel();
	void Initialize();
	bool IsFinished();
	void Execute() {};
	void End() {};
	void Interrupted() {};
};

#endif // START_HOPPER_WHEEL_H
