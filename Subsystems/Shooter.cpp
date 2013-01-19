/**
* @file Shooter.cpp
* @brief Implementation of the Shooter subsystem
* @author Nyle Rodgers
*/

#include "Shooter.h"
#include "../Robotmap.h"

// TODO: Tune the PID 
const float Shooter::P = 0.0,
            Shooter::I = 0.0,
            Shooter::D = 0.0;

const float Shooter::SHOOTER_SPEED = 0.0;

const float Shooter::MAX_RPS = 0.0;

const double Shooter::ENCODER_RESOLUTION = 256.0;

const float Shooter::MAX_PERCENT_ERROR = 1.0;

/**
 * Initialize the shooter's PID controller for the second wheel and the motor
 * controllers for both wheels.
 *
 * @author Nyle Rodgers
 */
Shooter::Shooter() :
	Subsystem("Shooter"),
	motor0 ( new Talon( ROBOT_MAP.DIGITAL_MODULE_PORT_CHANNEL,
	                     ROBOT_MAP.SHOOTER_MOTOR_0_CHANNEL ) ),
	motor1 ( new Talon( ROBOT_MAP.DIGITAL_MODULE_PORT_CHANNEL,
	                     ROBOT_MAP.SHOOTER_MOTOR_1_CHANNEL ) ),
	encoder ( new Encoder( ROBOT_MAP.DIGITAL_MODULE_PORT_CHANNEL,
	                        ROBOT_MAP.SHOOTER_ENCODER_A_CHANNEL,
	                        ROBOT_MAP.DIGITAL_MODULE_PORT_CHANNEL,
	                        ROBOT_MAP.SHOOTER_ENCODER_B_CHANNEL ) ),
	controller(0),
	pusher( new Relay( ROBOT_MAP.DIGITAL_MODULE_PORT_CHANNEL,
	                   ROBOT_MAP.SHOOTER_PUSHER_SPIKE_CHANNEL,
	                   kForwardOnly) ),
	loader ( new Solenoid (ROBOT_MAP.SOLENOID_MODULE_PORT_CHANNEL,
	                       ROBOT_MAP.SHOOTER_LOADER_SOLENOID_CHANNEL_EXTEND,
	                       ROBOT_MAP.SHOOTER_LOADER_SOLENOID_CHANNEL_RETRACT ) ){
	controller = new PIDController( P, I, D, encoder, motor1 );
	controller->SetDistancePerPulse( 1 / ENCODER_RESOLUTION );
	controller->SetInputRange( -MAX_RPS, MAX_RPS );
	controller->SetOutputRange( -1, 1 );
	controller->SetPercentTolerance( MAX_PERCENT_ERROR );
	controller->SetSetpoint(0.0);
	controller->Enable();
}

/**
 * Set both shooter motors to a speed
 * 
 * @param[in] speed The speed at which to spin the shooter, in rotations/second
 *
 * @author Nyle Rodgers
 */
void Shooter::startShooter() {
	motor0->Set(1.0);
	controller->SetSetpoint(SHOOTER_SPEED);
}

/**
 * Set both shooter motors to 0.0
 * 
 * @author Nyle Rodgers
 */
void Shooter::stopShooter() {
	motor0->Set(0.0);
	controller->SetSetpoint(0.0);
}

/**
 * Extend the shooters loader solenoid
 * 
 * @author Nyle Rodgers
 */
void Shooter::extend() {
	loader->set(kForward);
}

/**
 * Retract the shooters loader solenoid
 * 
 * @author Nyle Rodgers
 */
void Shooter::retract() {
	loader->set(kReverse);
}

/**
 * Starts running the pusher motor. This should be done at the begining of the
 * match
 * 
 * @author Nyle Rodgers
 */
void Shooter::startPusher() {
	pusher->Set(kOn);
}
