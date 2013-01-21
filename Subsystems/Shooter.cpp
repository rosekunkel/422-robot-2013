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
	initialMotor( new Talon( DIGITAL_MODULE_PORT,
	                         INITIAL_SHOOTER_WHEEL_CHANNEL ) ),
	secondMotor( new Talon( DIGITAL_MODULE_PORT,
	                        SECOND_SHOOTER_WHEEL_CHANNEL ) ),
	encoder( new Encoder( DIGITAL_MODULE_PORT,
	                      SHOOTER_ENCODER_CHANNEL_A,
	                      DIGITAL_MODULE_PORT,
	                      SHOOTER_ENCODER_CHANNEL_B ) ),
	initialMotorController(0), // Initialize to 0, because we need the motor and encoder to
	               // be initialized before setting up PID
	hopperWheel( new Relay( DIGITAL_MODULE_PORT,
	                        HOPPER_WHEEL_CHANNEL,
	                        Relay::kForwardOnly) ),
	diskPusher( new DoubleSolenoid( SOLENOID_MODULE_PORT,
	                                EXTEND_DISK_PUSHER_CHANNEL,
	                                RETRACT_DISK_PUSHER_CHANNEL ) ) {

	encoder->SetDistancePerPulse( 1 / ENCODER_RESOLUTION );
	initialMotorController = new PIDController( P, I, D,
	                                            encoder, initialMotor );
	initialMotorController->SetInputRange( -MAX_RPS, MAX_RPS );
	initialMotorController->SetOutputRange( -1, 1 );
	initialMotorController->SetPercentTolerance( MAX_PERCENT_ERROR );
	initialMotorController->SetSetpoint(0.0);
	initialMotorController->Enable();
}

/**
 * Set both shooter motors to their predetermined speed. The second motor spins
 * at full speed and the inital motor uses PID to spin at SHOOTER_SPEED.
 *
 * @author Nyle Rodgers
 * @author William Kunkel
 */
void Shooter::startShooter() {
	secondMotor->Set(1.0);
	initialMotorController->SetSetpoint(SHOOTER_SPEED);
}

/**
 * Set both shooter motors to 0.0.
 * 
 * @author Nyle Rodgers
 * @author William Kunkel
 */
void Shooter::stopShooter() {
	secondMotor->Set(0.0);
	initialMotorController->SetSetpoint(0.0);
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
