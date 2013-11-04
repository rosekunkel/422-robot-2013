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
#ifndef USE_PISTON_ARTICULATOR
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
	
	/// Move the acticulator up at full speed
	void moveUp();
	
	/// Move the articulator down at full speed
	void moveDown();
	
	/// Stop moving the articulator
	void stop();
	
	void resetEncoder();
	
	double getDisplacement();
	
private:
	Talon *motor;
	Encoder *encoder;
	DigitalInput *topLimitSwitch,
	             *bottomLimitSwitch;
	
	static const int ENCODER_RESOLUTION,
	                 ENCODER_GEAR_TEETH,
	                 SCREW_GEAR_TEETH;

	static const float SCREW_LEAD,
		               DISTANCE_PER_TICK;

	DriverStationLCD *dashboard;
};
#endif // USE_PISTON_ARTICULATOR
#endif // SHOOTER_ARTICULATOR_H
