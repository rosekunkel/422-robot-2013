/**
* @file Shooter.H
* @brief Decleration of the Shooter subsystem
* @author Nyle Rodgers
*/

#ifndef SHOOTER_H
#define SHOOTER_H
#include "WPILib.h"

/**
* @brief The Shooter subsystem
* 
* Controlls the robot's shooter.
*/
class Shooter: public Subsystem {
private:
	Talon *motor0, *motor1;
	Encoder *encoder;
	PIDController *controller;
	
	Relay *pusher;
	DoubleSolenoid *loader;
	
	static const float P,I,D;
	
	/// The speed at which the second shooter motor should spin
	static const float SHOOTER_SPEED;
	/// The maximum speed of the shooter motors in rotations per second
	static const float MAX_RPS;
	/// Ticks per revultion of the encoder
	static const float ENCODER_RESOLUTION;
	/// Maximum acceptable error between the setpoint and the actual speed
	static const float MAX_PERCENT_ERROR;
public:
	/// Initialize the Shooter subsystem.
	Shooter();
	/// Sets the shooter's motors to their respective speeds.
	void startShooter();
	/// Stop both of the shooter's motors.
	void stopShooter();
	/// Extend the shooter's loader solenoid.
	void extend();
	/// Retract the shooter's loader solenoid.
	void retract();
	/// Starts running the pusher motor.
	void startPusher();
	/// Stops running the pusher motor.
	void stopPusher();
};

#endif //SHOOTER_H
