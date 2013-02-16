/**
 * @file MoveShooterArticulator.h
 * @brief Declaration of the MoveShooterArticulator command
 * @author Nyle Rodgers
 */
#ifndef MOVESHOOTERARTICULATOR_H
#define MOVESHOOTERARTICULATOR_H

#include "../CommandBase.h"

/**
 * @brief The command to move the shooter arciculator
 * 
 * Operates the shooter articulator, using bang-bang controll to move it to
 * a set angle
 *
 * @author Nyle
 */
class MoveShooterArticulator: public CommandBase {
public:
	/// Constructor for the MoveShooterArticulator command
	MoveShooterArticulator();
	
	/// Initilize the command
	void Initialize();
	
	/// Move the articulator
	void Execute();
	
	/// See if it is at the proper position (+/- MAX_ERROR)
	bool IsFinished();
	
	/// Implement virtual method and do nothing
	void End() {};
	
	/// Implement virtual method and do nothing
	void Interrupted() {};
private:
	/// Maximum acceptable error, in degrees
	static const float MAX_ERROR;
	/// The angle to set the shooter articulator
	float setpoint;// TODO: set way to set this
};

#endif //MOVESHOOTERARTICULATOR_H
