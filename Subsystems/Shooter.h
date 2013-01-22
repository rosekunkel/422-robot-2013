/**
* @file Shooter.h
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
public:
	/// Initialize the Shooter subsystem.
	Shooter();

	/// Sets the shooter's motors to their respective speeds.
	void startShooter();

	/// Stop both of the shooter's motors.
	void stopShooter();

	/// Extend the disk pusher solenoid.
	void extend();

	/// Retract the disk pusher solenoid.
	void retract();

	/// Starts running the hopper motor.
	void startHopperWheel();

	/// Stops running the hopper motor.
	void stopHopperWheel();

private:
	Talon *secondMotor, *initialMotor;
	Encoder *encoder;
	PIDController *initialMotorController;
	
	Relay *hopperWheel;
	DoubleSolenoid *diskPusher;
	
	static const float P,I,D;
	
	/// The speed at which the initial shooter motor should spin
	static const float SHOOTER_SPEED;

	/// The maximum speed of the shooter motors in rotations per second
	static const float MAX_RPS;

	/// Ticks per revultion of the encoder
	static const float ENCODER_RESOLUTION;

	/// Maximum acceptable error between the setpoint and the actual speed
	static const float MAX_PERCENT_ERROR;
};

#endif //SHOOTER_H
