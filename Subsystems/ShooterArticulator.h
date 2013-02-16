/**
* @file Shooter.h
* @brief Decleration of the Shooter subsystem
* @author Nyle Rodgers
*/
#ifndef SHOOTERARTICULATOR_H
#define SHOOTERARTICULATOR_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 * @brief The shooter articulation subsystem
 * 
 * This subsystem controls the vertical aim of the shooter
 *
 * @author Nyle
 */
class ShooterArticulator: public Subsystem {
public:
	/// Constructor for the ShooterArticulator subsystem
	ShooterArticulator();
	
	/// Set the default command
	void InitDefaultCommand();
	
	/// Get the current angle, in degrees, above horizontal
	double getAngle();
	
	/// Move the acticulator up at full speed
	void moveUp();
	
	/// Move the articulator down at full speed
	void moveDown();
	
	/// Stop moving the articulator
	void stop();
private:
	Talon *motor;
	AnalogChannel *potentiometer;
	
	static const float ZERO_DEGREE_VOLTAGE,
	                   ONE_EIGHTY_DEGREE_VOLTAGE;
};

#endif //SHOOTERARTICULATOR_H
