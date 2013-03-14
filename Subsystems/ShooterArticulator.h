/**
 * @file Shooter.h
 * @brief Decleration of the Shooter subsystem
 * @author Nyle Rodgers
 */
#ifndef SHOOTER_ARTICULATOR_H
#define SHOOTER_ARTICULATOR_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../CompilationSettings.h"

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
	DigitalInput *topLimitSwitch,
	             *bottomLimitSwitch;
	
	static const float ENCODER_RESOLUTION,
					   DISTANCE_PER_REVOLUTION,
					   BASE_LENGTH,
					   SHOOTER_LENGTH,
					   ARTICULATOR_MOUNT_LENGTH,
					   // The length which the articulator shaft is at when 
					   // the encoder reads zero. This is measured from the 
					   // closest point of the line the shaft falls on to the 
					   // pivot of the mount for the shaft motor to the pivot 
					   // of the shaft on the shooter
					   ARTICULATOR_SHAFT_ZERO,
					   STARTING_DISTANCE;
	DriverStationLCD *dashboard;
};

#endif //SHOOTER_ARTICULATOR_H
