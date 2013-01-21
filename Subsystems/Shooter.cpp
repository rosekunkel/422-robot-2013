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
	initialMotor( new Talon( DIGITAL_MODULE_PORT,
	                         INITIAL_SHOOTER_WHEEL_CHANNEL ) ),
	secondMotor( new Talon( DIGITAL_MODULE_PORT_CHANNEL,
	                        SECOND_SHOOTER_WHEEL_CHANNEL ) ),
	encoder( new Encoder( DIGITAL_MODULE_PORT,
	                      SHOOTER_ENCODER_CHANNEL_A,
	                      DIGITAL_MODULE_PORT,
	                      SHOOTER_ENCODER_CHANNEL_B ) ),
	controller(0),
	hopperWheel( new Relay( DIGITAL_MODULE_PORT,
	                        HOPPER_WHEEL_CHANNEL,
	                        Relay::kForwardOnly) ),
	diskPusher( new DoubleSolenoid( SOLENOID_MODULE_PORT,
	                                EXTEND_DISK_PUSHER_CHANNEL,
	                                RETRACT_DISK_PUSHER_CHANNEL ) ) {

	encoder->SetDistancePerPulse( 1 / ENCODER_RESOLUTION );
	controller = new PIDController( P, I, D, encoder, initialMotor );
	controller->SetInputRange( -MAX_RPS, MAX_RPS );
	controller->SetOutputRange( -1, 1 );
	controller->SetPercentTolerance( MAX_PERCENT_ERROR );
	controller->SetSetpoint(0.0);
	controller->Enable();
}

/**
 * Set both shooter motors to their predetermined speed. The second motor spins
 * at full speed and the second uses PID to spin at SHOOTER_SPEED.
 *
 * @author Nyle Rodgers
 */
void Shooter::startShooter() {
	secondMotor->Set(1.0);
	controller->SetSetpoint(SHOOTER_SPEED);
}

/**
 * Set both shooter motors to 0.0.
 * 
 * @author Nyle Rodgers
 */
void Shooter::stopShooter() {
	secondMotor->Set(0.0);
	controller->SetSetpoint(0.0);
}

/**
 * Extend the shooter's disk pusher solenoid.
 * 
 * @author Nyle Rodgers
 */
void Shooter::extend() {
	diskPusher->Set(DoubleSolenoid::kForward);
}

/**
 * Retract the shooter's disk pusher solenoid.
 * 
 * @author Nyle Rodgers
 */
void Shooter::retract() {
	diskPusher->Set(DoubleSolenoid::kReverse);
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
