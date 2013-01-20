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

const float Shooter::ENCODER_RESOLUTION = 256.0;

const float Shooter::MAX_PERCENT_ERROR = 1.0;

/**
 * Initialize the shooter's PID controller, motor controllers, encoder,
 * double solenoid, and spike, and get them set up.
 * 
 * @author Nyle Rodgers
 */
Shooter::Shooter() :
	Subsystem("Shooter"),
	motor0 ( new Talon( DIGITAL_MODULE_PORT_CHANNEL,
	                     SHOOTER_MOTOR_0_CHANNEL ) ),
	motor1 ( new Talon( DIGITAL_MODULE_PORT_CHANNEL,
	                     SHOOTER_MOTOR_1_CHANNEL ) ),
	encoder ( new Encoder( DIGITAL_MODULE_PORT_CHANNEL,
	                        SHOOTER_ENCODER_A_CHANNEL,
	                        DIGITAL_MODULE_PORT_CHANNEL,
	                        SHOOTER_ENCODER_B_CHANNEL ) ),
	controller(0),
	pusher( new Relay( DIGITAL_MODULE_PORT_CHANNEL,
	                   SHOOTER_PUSHER_SPIKE_CHANNEL,
	                   Relay::kForwardOnly) ),
	loader ( new DoubleSolenoid (SOLENOID_MODULE_PORT_CHANNEL,
	                       SHOOTER_LOADER_SOLENOID_CHANNEL_EXTEND,
	                       SHOOTER_LOADER_SOLENOID_CHANNEL_RETRACT ) ){
	encoder->SetDistancePerPulse( 1 / ENCODER_RESOLUTION );
	controller = new PIDController( P, I, D, encoder, motor1 );
	controller->SetInputRange( -MAX_RPS, MAX_RPS );
	controller->SetOutputRange( -1, 1 );
	controller->SetPercentTolerance( MAX_PERCENT_ERROR );
	controller->SetSetpoint(0.0);
	controller->Enable();
}

/**
 * Set both shooter motors to their predetermined speed. The first motor spins
 * at full speed and the second uses PID to spin at SHOOTER_SPEED.
 *
 * @author Nyle Rodgers
 */
void Shooter::startShooter() {
	motor0->Set(1.0);
	controller->SetSetpoint(SHOOTER_SPEED);
}

/**
 * Set both shooter motors to 0.0.
 * 
 * @author Nyle Rodgers
 */
void Shooter::stopShooter() {
	motor0->Set(0.0);
	controller->SetSetpoint(0.0);
}

/**
 * Extend the shooter's loader solenoid.
 * 
 * @author Nyle Rodgers
 */
void Shooter::extend() {
	loader->Set(DoubleSolenoid::kForward);
}

/**
 * Retract the shooter's loader solenoid.
 * 
 * @author Nyle Rodgers
 */
void Shooter::retract() {
	loader->Set(DoubleSolenoid::kReverse);
}

/**
 * Starts running the pusher motor. This should be done at the begining of the
 * match.
 * 
 * @author Nyle Rodgers
 */
void Shooter::startPusher() {
	pusher->Set(Relay::kOn);
}

/**
 * Starts running the pusher motor. This should be done at the begining of the
 * match.
 * 
 * @author Nyle Rodgers
 */
void Shooter::stopPusher() {
	pusher->Set(Relay::kOff);
}
