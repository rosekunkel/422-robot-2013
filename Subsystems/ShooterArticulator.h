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
	
	/// Get the current angle, in radians, above horizontal
	double getAngle();
	
	/// Move the acticulator up at full speed
	void moveUp();
	
	/// Move the articulator down at full speed
	void moveDown();
	
	/// Stop moving the articulator
	void stop();
private:
	Talon *motor;
	Encoder *encoder;
	AnalogChannel *potentiometer;
	DigitalInput *topLimitSwitch,
	             *bottomLimitSwitch;
	
	static const float ZERO_RADIAN_VOLTAGE,
	                   ONE_RADIAN_VOLTAGE,
	                   ENCODER_RESOLUTION;
};

#endif //SHOOTERARTICULATOR_H
