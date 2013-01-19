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
* Controlls the robot's Shooter.
*/
class Shooter: public Subsystem {
private:
	Talon *motor0, *motor1;
	Encoder *encoder;
	PIDController *controller;
	
	Relay *pusher;
	DoubleSolenoid *loader;
	
	static const float P,I,D;
	
	/// The speed at which the seconnd shooter motor shuold spin
	static const float SHOOTER_SPEED;
	/// The maximum speed of the shooter motors in rotations per second
	static const float MAX_RPS;
	/// Ticks per revultion of the encoder
	static const double ENCODER_RESOLUTION;
	/// Maximum acceptable error between the setpoint and the actual speed
	static const double MAX_PERCENT_ERROR;
public:
	/// Initialize the Shooter subsystem.
	Shooter();
	/// Sets the shooter motors to their respective speeds.
	void startShooter();
	/// Stop both shooter motors.
	void stopShooter();
	/// Extend the shooters loader solenoid.
	void extend();
	/// Retract the shooters loader solenoid.
	void retract();
	/// Starts running the pusher motor.
	void startPusher();
};

#endif //SHOOTER_H
