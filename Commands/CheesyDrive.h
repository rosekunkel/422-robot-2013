/**
 * @file CheesyDrive.h
 * @brief Declaration of the CheesyDrive command
 * @author William Kunkel
 */

#ifndef CHEESY_DRIVE_H
#define CHEESY_DRIVE_H

#include "../CommandBase.h"
#include "../CompilationSettings.h"

/**
 * @brief The CheesyDrive command
 *
 * Drive the robot using "Cheesy Drive", where one of the joysticks controls
 * forward-and-back motion and the other controls turning.
 *
 * @author William Kunkel
 */
class CheesyDrive: public CommandBase {
public:
	/// Constructor for the CheesyDrive command
	CheesyDrive();
	
	/// Implement virtual method and do nothing
	void Initialize() {};

	/// Drive from joysticks
	void Execute();

	/// Return false
	bool IsFinished();

	/// Implement virtual method and do nothing
	void End() {};

	/// Implement virtual method and do nothing
	void Interrupted() {};
private:
	float valueWithDeadzone( float, float );
	float truncateOutOfBounds( float );
	void updateMultipliers();

	static const float DEADZONE;
	float forwardMultiplier,
	      turningMultiplier;
	bool tankDrive;
};

#endif // CHEESY_DRIVE_H
