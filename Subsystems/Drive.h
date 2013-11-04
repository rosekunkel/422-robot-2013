/**
 * @file Drive.h
 * @brief Declaration of the Drive subsystem
 * @author William Kunkel
 * @author Nyle Rodgers
 */

#ifndef DRIVE_H
#define DRIVE_H

#include "WPILib.h"
#include "../CompilationSettings.h"
#include "PIDTalonWrapper.h"

/**
 * @brief The Drive subsystem
 * 
 * Controls the drive base of the robot.
 */
class Drive: public Subsystem {
public:
	/// Constructor for the Drive subsystem
	Drive();
	
	/// Set the default command.
	void InitDefaultCommand();

	/// Drive straight at @a speed, which can be positive or negative.
	void driveStraight( float speed );

	/// Set the RPS of each motor independently.
	void setMotorSpeeds( float leftSpeed, float rightSpeed );

	/// Set the motors as a percentage of their top speed, from -1.0 to 1.0.
	void setMotorsNormalized( float leftSpeed, float rightSpeed );

	/// Slow to a stop smoothly and quickly.
	void stop();
	
	void stopAndDisable();
	
	void setMotorsNormalizedDirect( float leftSpeed, float rightSpeed );

	void resetEncoders();

	float getRotations();
	float getAmountSpun();
	
private:
	PIDTalonWrapper *leftMotor, *rightMotor;
	Encoder *leftEncoder, *rightEncoder, *testEncoder;
	PIDController *leftController, *rightController;
	static const float P, I, D;
	
	/// Maximum speed of the drive shaft in rotations/second
	static const float MAX_RPS;

	/// Ticks per revolution for the encoders
	static const double ENCODER_RESOLUTION;

	/// Maximum acceptable error between the setpoint and the speed
	static const float MAX_PERCENT_ERROR;
};

#endif // DRIVE_H
