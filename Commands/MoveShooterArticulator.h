// TODO: Figure out what the hell this is

/**
 * @file MoveShooterArticulator.h
 * @brief Declaration of the MoveShooterArticulator command
 * @author Nyle Rodgers
 */

#ifndef MOVE_SHOOTER_ARTICULATOR_H
#define MOVE_SHOOTER_ARTICULATOR_H

#include "../CommandBase.h"
#include "../CompilationSettings.h"

/**
 * @brief The command to move the shooter arciculator
 * 
 * Operates the shooter articulator, using bang-bang control to move it to
 * a set angle
 *
 * @author Nyle
 */
class MoveShooterArticulator: public CommandBase {
public:
	/// Constructor for the MoveShooterArticulator command
	MoveShooterArticulator( float angle );
	
	/// Initilize the command
	void Initialize();
	
	/// Move the articulator
	void Execute();
	
	/// See if it is at the proper position (+/- MAX_ERROR)
	bool IsFinished();
	
	/// Implement virtual method and do nothing
	void End() {}
	
	/// Implement virtual method and do nothing
	void Interrupted() {}
private:
	/// Maximum acceptable error, in degrees
	static const float MAX_ERROR;
	/// The angle to set the shooter articulator
	float setpoint;
};

#endif // MOVE_SHOOTER_ARTICULATOR_H
