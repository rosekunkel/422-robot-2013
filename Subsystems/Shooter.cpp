/**
 * @file Shooter.cpp
 * @brief Implementation of the Shooter subsystem
 * @author Nyle Rodgers
 * @author William Kunkel
 */

#include "Shooter.h"
#include "../RobotMap.h"

#ifdef USE_BANG_BANG
#include "../Commands/BangBangShooterControl.h"
#else
#include "../Commands/OperateShooter.h"
#endif

#ifndef USE_BANG_BANG
const float Shooter::P = 0.01,
            Shooter::I = 0.0,
            Shooter::D = 0.025;

const float Shooter::MAX_RPS = 45.0;

const float Shooter::MAX_PERCENT_ERROR = 5.0;
#endif

const float Shooter::ENCODER_RESOLUTION = 64.0;

/**
 * Initialize the shooter's PID controller, motor controllers, encoder,
 * double solenoid, and spike, and get them set up.
 * 
 * @author Nyle Rodgers
 * @author William Kunkel
 */
Shooter::Shooter() :
	Subsystem("Shooter"),
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
#ifdef USE_BANG_BANG
	firstMotor( new Talon( DIGITAL_MODULE_PORT,
		                   FIRST_SHOOTER_WHEEL_CHANNEL ) ),
	secondMotor( new Talon( DIGITAL_MODULE_PORT,
		                    SECOND_SHOOTER_WHEEL_CHANNEL ) )
#else
	firstMotor( new PIDTalonWrapper( DIGITAL_MODULE_PORT,
	                                 FIRST_SHOOTER_WHEEL_CHANNEL ) ),
	secondMotor( new PIDTalonWrapper( DIGITAL_MODULE_PORT,
	                                  SECOND_SHOOTER_WHEEL_CHANNEL ) ),
	firstMotorController(0),
	secondMotorController(0) // Initialize to 0, because we need the motor and encoder to
	                          // be initialized before setting up PID
#endif
	{

	firstEncoder->SetDistancePerPulse( 1 / ENCODER_RESOLUTION );
	secondEncoder->SetDistancePerPulse( 1 / ENCODER_RESOLUTION );

#ifndef USE_BANG_BANG
	firstEncoder->SetPIDSourceParameter(Encoder::kRate);
	secondEncoder->SetPIDSourceParameter(Encoder::kRate);
#endif
	
	firstEncoder->Start();
	secondEncoder->Start();

#ifndef USE_BANG_BANG
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
#endif
}

void Shooter::InitDefaultCommand() {
#ifdef USE_BANG_BANG
	SetDefaultCommand( new BangBangShooterControl() );
#else
	SetDefaultCommand( new OperateShooter() );
#endif
}

void Shooter::setSetpoint( float setpoint ) {
	firstMotorController->SetSetpoint( -setpoint );
	secondMotorController->SetSetpoint( -setpoint );
}

float Shooter::getFirstWheelSpeed() {
	return firstEncoder->GetRate();
}

float Shooter::getSecondWheelSpeed() {
	return secondEncoder->GetRate();
}

#ifdef USE_BANG_BANG
void Shooter::runFirstWheel() {
	firstMotor->Set(-1.0);
}
void Shooter::coastFirstWheel() {
	firstMotor->Set(0.0);
}

void Shooter::runSecondWheel() {
	secondMotor->Set(-1.0);
}
void Shooter::coastSecondWheel() {
	secondMotor->Set(0.0);
}

#else
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

void Shooter::setSetpoints(float firstSetpoint, float secondSetpoint) {
	firstMotorController->Enable();
	secondMotorController->Enable();
	firstMotorController->SetSetpoint(-firstSetpoint);
	secondMotorController->SetSetpoint(-secondSetpoint);
}

bool Shooter::isAtSpeed() {
	return firstMotorController->OnTarget()
		&& secondMotorController->OnTarget();
}
#endif
