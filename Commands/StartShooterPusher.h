/**
* @file Shooter.cpp
* @brief Definition start shooter pusher command
* @author Nyle Rodgers
*/

#ifndef STARTSHOOTERPUSHER_H
#define STARTSHOOTERPUSHER_H

#include "../CommandBase.h"

/**
 * @brief Starts the pusher motor
 *
 * This should be run at the beginning of the match
 */

class StartShooterPusher: public CommandBase {
public:
	StartShooterPusher();
	virtual void Initialize();
	virtual bool IsFinished();
};

#endif // STARTSHOOTERPUSHER_H
