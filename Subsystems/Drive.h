/**
 * @file Drive.h
 * @brief Declaration of the Drive subsystem
 * @author William Kunkel
 */

#ifndef DRIVE_H
#define DRIVE_H

#include "WPILib.h"

/**
 * @brief The Drive subsystem
 * 
 * Controls the drive base of the robot.
 */
class Drive: public Subsystem {
public:
	/// Constructor for the Drive subsystem
	Drive();

	/// Drive straight at @a speed, which can be positive or negative.
	void driveStraight( float speed );

	/// Set the RPS of each motor independently.
	void setMotorSpeeds( float leftSpeed, float rightSpeed );

	/// Set the motors as a percentage of their top speed, from -1.0 to 1.0.
	void setMotorsNormailzed( float leftSpeed, float rightSpeed );

	/// Slow to a stop smoothly and quickly.
	void stop();

private:
	Talon *leftMotor, *rightMotor;
	Encoder *leftEncoder, *rightEncoder;
	PIDController *leftController, *rightController;
	static const float P, I, D;
	
	/// Maximum speed of the drive shaft in rotations/second
	static const float MAX_RPS;

	/// Ticks per revolution for the encoders
	static const double ENCODER_RESOLUTION;

	/// Maximum acceptable error between the setpoint and the speed
	static const double MAX_PERCENT_ERROR;
};

#endif // DRIVE_H
