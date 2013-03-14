/**
* @file Shooter.h
* @brief Decleration of the Shooter subsystem
* @author Nyle Rodgers
*/

#ifndef SHOOTER_H
#define SHOOTER_H
#include "WPILib.h"
#include "../CompilationSettings.h"

#ifndef USE_BANG_BANG
#include "PIDTalonWrapper.h"
#endif
/**
* @brief The Shooter subsystem
* 
* Controlls the robot's shooter.
*/
class Shooter: public Subsystem {
public:
	/// Initialize the Shooter subsystem.
	Shooter();
	
	/// Set the default command.
	void InitDefaultCommand();

	void setSetpoint( float setpoint );
	float getFirstWheelSpeed();
	float getSecondWheelSpeed();

#ifdef USE_BANG_BANG
	void runFirstWheel();
	void coastFirstWheel();
	
	void runSecondWheel();
	void coastSecondWheel();
#else
	/// Stop both of the shooter's motors.
	void stopShooter();

	bool isAtSpeed();
	
	void setSetpoints(float firstSetpoint, float secondSetpoint);
#endif
	
private:
	Encoder *firstEncoder, *secondEncoder;
	
	/// Ticks per revultion of the encoder
	static const float ENCODER_RESOLUTION;
	
#ifndef USE_BANG_BANG
	// firstMotor refers to the motor which the frisbee will contact first
	PIDTalonWrapper *firstMotor, *secondMotor; 
	PIDController *firstMotorController, *secondMotorController;
	
	static const float P,I,D;

	/// The maximum speed of the shooter motors in rotations per second
	static const float MAX_RPS;

	/// Maximum acceptable error between the setpoint and the actual speed
	static const float MAX_PERCENT_ERROR;
#else
	Talon *firstMotor, *secondMotor;
#endif
};

#endif //SHOOTER_H
