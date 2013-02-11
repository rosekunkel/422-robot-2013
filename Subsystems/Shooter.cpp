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

const float Shooter::FIRST_MOTOR_SPEED = 0.0,
		    Shooter::SECOND_MOTOR_SPEED = 0.0;

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
	firstMotor( new PIDTalonWrapper( DIGITAL_MODULE_PORT,
	                                 FIRST_SHOOTER_WHEEL_CHANNEL ) ),
	secondMotor( new PIDTalonWrapper( DIGITAL_MODULE_PORT,
	                                  SECOND_SHOOTER_WHEEL_CHANNEL ) ),
	firstEncoder( new Encoder( DIGITAL_MODULE_PORT,
	                           FIRST_SHOOTER_ENCODER_CHANNEL_A,
	                           DIGITAL_MODULE_PORT,
	                           FIRST_SHOOTER_ENCODER_CHANNEL_B,
	                           false,
	                           Encoder::k1X ) ),
	secondEncoder( new Encoder( DIGITAL_MODULE_PORT,
						        SECOND_SHOOTER_ENCODER_CHANNEL_A,
						        DIGITAL_MODULE_PORT,
						        SECOND_SHOOTER_ENCODER_CHANNEL_B,
						        false,
		                        Encoder::k1X ) ),
	firstMotorController(0),
	secondMotorController(0), // Initialize to 0, because we need the motor and encoder to
	                          // be initialized before setting up PID
	diskPusher( new DoubleSolenoid( SOLENOID_MODULE_PORT,
	                                EXTEND_DISK_PUSHER_CHANNEL,
	                                RETRACT_DISK_PUSHER_CHANNEL ) ) {

	firstEncoder->SetDistancePerPulse( 1 / ENCODER_RESOLUTION );
	secondEncoder->SetDistancePerPulse( 1 / ENCODER_RESOLUTION );
	
	firstEncoder->SetPIDSourceParameter(Encoder::kRate);
	secondEncoder->SetPIDSourceParameter(Encoder::kRate);
	
	firstEncoder->Start();
	secondEncoder->Start();
	
	firstMotorController = new PIDController( P, I, D, firstEncoder, firstMotor );
	secondMotorController = new PIDController( P, I, D, secondEncoder, secondMotor );
	
	firstMotorController->SetInputRange( -MAX_RPS, MAX_RPS );
	secondMotorController->SetInputRange( -MAX_RPS, MAX_RPS );
	
	firstMotorController->SetOutputRange( -1, 1 );
	secondMotorController->SetOutputRange( -1, 1 );
	
	firstMotorController->SetPercentTolerance( MAX_PERCENT_ERROR );
	secondMotorController->SetPercentTolerance( MAX_PERCENT_ERROR );
	
	firstMotorController->SetSetpoint(0.0);
	secondMotorController->SetSetpoint(0.0);
	
	firstMotorController->Enable();
	secondMotorController->Enable();
}

/**
 * Set both shooter motors to their predetermined speed. The initial motor spins
 * are FIRST_MOTOR_SPEED and SECOND_MOTOR_SPEED.
 *
 * @author Nyle Rodgers
 * @author William Kunkel
 */
void Shooter::startShooter() {
	firstMotorController->SetSetpoint(FIRST_MOTOR_SPEED);
	secondMotorController->SetSetpoint(SECOND_MOTOR_SPEED);
}

/**
 * Set both shooter motor setpoints to 0.0.
 * 
 * @author Nyle Rodgers
 * @author William Kunkel
 */
void Shooter::stopShooter() {
	firstMotorController->SetSetpoint(0.0);
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
