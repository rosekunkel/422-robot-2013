/**
 * @file Shooter.cpp
 * @brief Implementation of the Shooter subsystem
 * @author Nyle Rodgers
 * @author William Kunkel
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
 * @author William Kunkel
 */
Shooter::Shooter() :
	Subsystem("Shooter"),
	secondMotor( new Talon( DIGITAL_MODULE_PORT,
	                         INITIAL_SHOOTER_WHEEL_CHANNEL ) ),
	initialMotor( new Talon( DIGITAL_MODULE_PORT_CHANNEL,
	                        SECOND_SHOOTER_WHEEL_CHANNEL ) ),
	encoder( new Encoder( DIGITAL_MODULE_PORT,
	                      SHOOTER_ENCODER_CHANNEL_A,
	                      DIGITAL_MODULE_PORT,
	                      SHOOTER_ENCODER_CHANNEL_B ) ),
	controller(0), // Initialize to 0, because we need the motor and encoder to
	               // be secondized before setting up PID
	hopperWheel( new Relay( DIGITAL_MODULE_PORT,
	                        HOPPER_WHEEL_CHANNEL,
	                        Relay::kForwardOnly) ),
	diskPusher( new DoubleSolenoid( SOLENOID_MODULE_PORT,
	                                EXTEND_DISK_PUSHER_CHANNEL,
	                                RETRACT_DISK_PUSHER_CHANNEL ) ) {

	encoder->SetDistancePerPulse( 1 / ENCODER_RESOLUTION );
	secondMotorController = new PIDController( P, I, D,
	                                            encoder, secondMotor );
	secondMotorController->SetInputRange( -MAX_RPS, MAX_RPS );
	secondMotorController->SetOutputRange( -1, 1 );
	secondMotorController->SetPercentTolerance( MAX_PERCENT_ERROR );
	secondMotorController->SetSetpoint(0.0);
	secondMotorController->Enable();
}

/**
 * Set both shooter motors to their predetermined speed. The initial motor spins
 * at full speed and the second motor uses PID to spin at SHOOTER_SPEED.
 *
 * @author Nyle Rodgers
 * @author William Kunkel
 */
void Shooter::startShooter() {
	initialMotor->Set(1.0);
	secondMotorController->SetSetpoint(SHOOTER_SPEED);
}

/**
 * Set both shooter motors to 0.0.
 * 
 * @author Nyle Rodgers
 * @author William Kunkel
 */
void Shooter::stopShooter() {
	initialMotor->Set(0.0);
	secondMotorController->SetSetpoint(0.0);
}

/**
 * Extend the shooter's disk pusher solenoid.
 * 
 * @author Nyle Rodgers
 * @author William Kunkel
 */
void Shooter::extend() {
	diskPusher->Set(DoubleSolenoid::kForward);
}

/**
 * Retract the shooter's disk pusher solenoid.
 * 
 * @author Nyle Rodgers
 * @author William Kunkel
 */
void Shooter::retract() {
	diskPusher->Set(DoubleSolenoid::kReverse);
}

/**
 * Starts running the spring-loaded hopper wheel motor
 *
 * @note This should be done at the begining of the match.
 * 
 * @author Nyle Rodgers
 * @author William Kunkel
 */
void Shooter::startHopperWheel() {
	hopperWheel->Set(Relay::kOn);
}

/**
 * Stops running the spring-loaded hopper wheel motor
 * 
 * @author Nyle Rodgers
 * @author William Kunkel
 */
void Shooter::stopHopperWheel() {
	hopperWheel->Set(Relay::kOff);
}
