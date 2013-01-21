/**
* @file Shooter.cpp
* @brief Implementation start shooter pusher command
* @author Nyle Rodgers
* @author William Kunkel
*/

#include "StartHopperWheel.h"

/**
 * Constructor for the command.
 *
 * @author Nyle Rodgers
 * @author William Kunkel
 */
StartHopperWheel::StartHopperWheel() {
	Requires(shooter);
}
/**
 * Starts the shooter motor; this is all that the command needs to do.
 *
 * @author Nyle Rodgers
 * @author William Kunkel
 */
void StartHopperWheel::Initialize() {
	shooter->startHopperWheel();
}

/**
 * Returns true, bucause everything is done in the initilization.
 *
 * @author Nyle Rodgers
 */
bool StartHopperWheel::IsFinished() {
	return true;
}
