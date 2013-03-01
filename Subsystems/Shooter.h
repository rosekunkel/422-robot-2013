/**
* @file Shooter.h
* @brief Decleration of the Shooter subsystem
* @author Nyle Rodgers
*/

#ifndef SHOOTER_H
#define SHOOTER_H
#include "WPILib.h"
#include "PIDTalonWrapper.h"

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
	
	/// Set the default command.
	void InitDefaultCommand();

	/// Stop both of the shooter's motors.
	void stopShooter();
	
	float getFirstWheelSpeed();
	
	float getSecondWheelSpeed();
	
	bool isAtSpeed();
	
	void setSetpoints(float firstSetpoint, float secondSetpoint);
	
	void goFullSpeed();
private:
	// firstMotor refers to the motor which the frisbee will contact first
	PIDTalonWrapper *firstMotor, *secondMotor; 
	Encoder *firstEncoder, *secondEncoder;
	PIDController *firstMotorController, *secondMotorController;
	
	static const float P,I,D;
	
	/// The speed at which the initial shooter motor should spin
	static const float FIRST_MOTOR_SPEED, SECOND_MOTOR_SPEED;

	/// The maximum speed of the shooter motors in rotations per second
	static const float MAX_RPS;

	/// Ticks per revultion of the encoder
	static const float ENCODER_RESOLUTION;

	/// Maximum acceptable error between the setpoint and the actual speed
	static const float MAX_PERCENT_ERROR;
	
	/// The maximum acceptable error for the isAtSpeed method, in RPS, should probably be given a better name
	static const float ACCEPTABLE_ERROR;
};

#endif //SHOOTER_H
