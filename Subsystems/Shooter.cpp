/**
 * @file Shooter.cpp
 * @brief Implementation of the Shooter subsystem
 * @author Nyle Rodgers
 * @author William Kunkel
 */

#include "Shooter.h"
#include "../RobotMap.h"
#include "../Commands/OperateShooter.h"

#include <iostream>
#include <cmath>

// TODO: Tune the PID
const float Shooter::P_FIRST = 0.01,
            Shooter::I_FIRST = 0.0,
            Shooter::D_FIRST = 0.03;
const float Shooter::P_SECOND = 0.015,
            Shooter::I_SECOND = 0.0,
            Shooter::D_SECOND = 0.03;

const float Shooter::FIRST_MOTOR_SPEED = 20.0,
		    Shooter::SECOND_MOTOR_SPEED = 20.0;

// TODO: Check number here
const float Shooter::FIRST_MOTOR_MAX_RPS = 60.0,
		    Shooter::SECOND_MOTOR_MAX_RPS = 65.0;

const float Shooter::ENCODER_RESOLUTION = 64.0;

const float Shooter::MAX_PERCENT_ERROR = 1.0;

const float Shooter::ACCEPTABLE_ERROR = 1.0;

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
	secondMotorController(0) // Initialize to 0, because we need the motor and encoder to
	                          // be initialized before setting up PID 
	{

	firstEncoder->SetDistancePerPulse( 1 / ENCODER_RESOLUTION );
	secondEncoder->SetDistancePerPulse( 1 / ENCODER_RESOLUTION );
	
	firstEncoder->SetPIDSourceParameter(Encoder::kRate);
	secondEncoder->SetPIDSourceParameter(Encoder::kRate);
	
	firstEncoder->Start();
	secondEncoder->Start();
	
	firstMotorController = new PIDController( P_FIRST, I_FIRST, D_FIRST, firstEncoder, firstMotor );
	secondMotorController = new PIDController( P_SECOND, I_SECOND, D_SECOND, secondEncoder, secondMotor );
	
	firstMotorController->SetInputRange( -FIRST_MOTOR_MAX_RPS, FIRST_MOTOR_MAX_RPS );
	secondMotorController->SetInputRange( -SECOND_MOTOR_MAX_RPS, SECOND_MOTOR_MAX_RPS );
	
	firstMotorController->SetOutputRange( -1, 1 );
	secondMotorController->SetOutputRange( -1, 1 );
	
	firstMotorController->SetPercentTolerance( MAX_PERCENT_ERROR );
	secondMotorController->SetPercentTolerance( MAX_PERCENT_ERROR );
	
	firstMotorController->SetSetpoint(0.0);
	secondMotorController->SetSetpoint(0.0);
	
	firstMotorController->Enable();
	secondMotorController->Enable();
}

void Shooter::InitDefaultCommand() {
	SetDefaultCommand( new OperateShooter() );
}


/**
 * Set both shooter motors to their predetermined speed. The initial motor spins
 * are FIRST_MOTOR_SPEED and SECOND_MOTOR_SPEED.
 *
 * @author Nyle Rodgers
 * @author William Kunkel
 */
void Shooter::startShooter() {
	firstMotorController->Enable();
	secondMotorController->Enable();
	firstMotorController->SetSetpoint(-FIRST_MOTOR_SPEED);
	secondMotorController->SetSetpoint(-SECOND_MOTOR_SPEED);
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
	firstMotorController->Disable();
	secondMotorController->Disable();
	firstMotor->Set(0.0);
	secondMotor->Set(0.0);
}

void Shooter::setSetpoints(float firstSetpoint, float secondStepoint) {
	firstMotorController->Enable();
	secondMotorController->Enable();
	firstMotorController->SetSetpoint(-firstSetpoint);
	secondMotorController->SetSetpoint(-secondStepoint);
}

float Shooter::getFirstWheelSpeed() {
	return firstEncoder->GetRate();
}

float Shooter::getSecondWheelSpeed() {
	return secondEncoder->GetRate();
}

float Shooter::getFirstWheelOfset() {
	return firstMotorController->GetSetpoint() - firstEncoder->GetRate();
}

float Shooter::getSecondWheelOfset() {
	return secondMotorController->GetSetpoint() - secondEncoder->GetRate();
}

bool Shooter::isAtSpeed() {
	return ( fabs( firstEncoder->GetRate() - firstMotorController->GetSetpoint() ) 
	       < ACCEPTABLE_ERROR) &&
	       ( fabs( secondEncoder->GetRate() - secondMotorController->GetSetpoint() ) 
	       < ACCEPTABLE_ERROR);
}
