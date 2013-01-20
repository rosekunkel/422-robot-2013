/**
* @file Shooter.cpp
* @brief Implementation start shooter pusher command
* @author Nyle Rodgers
*/

#include "StartShooterPusher.h"

/**
 * Constructor for the command.
 *
 * @author Nyle Rodgers
 */
StartShooterPusher::StartShooterPusher() {
	Requires(shooter);
}
/**
 * Starts the shooter motor; this is all that the command needs to do.
 *
 * @author Nyle Rodgers
 */
void StartShooterPusher::Initialize() {
	shooter->startPusher();
}

/**
 * Returns true, bucause everything is done in the initilization.
 *
 * @author Nyle Rodgers
 */
bool StartShooterPusher::IsFinished() {
	return true;
}
