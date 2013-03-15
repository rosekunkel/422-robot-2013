/**
 * @file Drive.cpp
 * @brief Implementation of the Drive subsystem
 * @author William Kunkel
 * @author Nyle Rodgers
 */

#include <cmath>
#include "Drive.h"
#include "../RobotMap.h"
#include "../Commands/CheesyDrive.h"

const float Drive::P = 0.07,
            Drive::I = 0.0,
            Drive::D = 0.0;

const float Drive::MAX_RPS = 13.5;

const double Drive::ENCODER_RESOLUTION = 256.0;

const float Drive::MAX_PERCENT_ERROR = 5.0;

/**
 * Initialize the PID controllers for each side of the drive, and enable them,
 * with an initial setpoint of 0.0.
 *
 * @author William Kunkel
 * @author Nyle Rodgers
 */
Drive::Drive() : 
	Subsystem("Drive"),
	leftMotor( new PIDTalonWrapper( DIGITAL_MODULE_PORT,
	                                LEFT_DRIVE_CHANNEL ) ),

	rightMotor( new PIDTalonWrapper( DIGITAL_MODULE_PORT,
	                                RIGHT_DRIVE_CHANNEL ) ),

	leftEncoder( new Encoder( DIGITAL_MODULE_PORT,
	                          LEFT_DRIVE_ENCODER_CHANNEL_A,
	                          DIGITAL_MODULE_PORT,
	                          LEFT_DRIVE_ENCODER_CHANNEL_B,
	                          false,
	                          Encoder::k1X ) ),

	rightEncoder( new Encoder( DIGITAL_MODULE_PORT,
	                           RIGHT_DRIVE_ENCODER_CHANNEL_A,
	                           DIGITAL_MODULE_PORT,
	                           RIGHT_DRIVE_ENCODER_CHANNEL_B,
	                           false,
	                           Encoder::k1X  ) ),
	// We need to use the encoders & talons to initialize this, so to be safe we
	// set it to a null pointer and assign in the constructor body.
	leftController(0),
	rightController(0) {
	
	leftMotor->Set(0.0);
	rightMotor->Set(0.0);
	
	leftEncoder->SetPIDSourceParameter(Encoder::kRate);
	rightEncoder->SetPIDSourceParameter(Encoder::kRate);
	
	leftEncoder->SetDistancePerPulse( 1 / ENCODER_RESOLUTION );
	rightEncoder->SetDistancePerPulse( 1 / ENCODER_RESOLUTION );
	
	rightEncoder->Start();
	leftEncoder->Start();

	leftController = new PIDController( P, I, D, leftEncoder, leftMotor );
	rightController = new PIDController( P, I, D, rightEncoder, rightMotor );

	leftController->SetInputRange( -MAX_RPS, MAX_RPS );
	rightController->SetInputRange( -MAX_RPS, MAX_RPS );

	leftController->SetOutputRange( -1, 1 );
	rightController->SetOutputRange( -1, 1 );

	leftController->SetPercentTolerance( MAX_PERCENT_ERROR );
	rightController->SetPercentTolerance( MAX_PERCENT_ERROR );

	leftController->SetSetpoint(0.0);
	rightController->SetSetpoint(0.0);

	leftController->Enable();
	rightController->Enable();
}

void Drive::InitDefaultCommand() {
	SetDefaultCommand( new CheesyDrive() );
}

/** 
 * Set both motors to the same setpoint, causing the robot to drive forwards or
 * backwards in a straight line
 * 
 * @param[in] speed The speed at which to drive the motors, in rotations/second
 * 
 * @author William Kunkel
 */
void Drive::driveStraight( float speed ) {
	leftController->Enable();
	rightController->Enable();
	leftController->SetSetpoint(speed);
	rightController->SetSetpoint(speed);
}

/** 
 * Drive each motor independently at a speed given in rotations/second.
 * 
 * @param[in] leftSpeed The speed to drive the left motor, in rotations/second
 * @param[in] rightSpeed The speed to drive the right motor, in rotations/second
 *
 * @author William Kunkel
 */
void Drive::setMotorSpeeds( float leftSpeed, float rightSpeed ) {
	leftController->Enable();
	rightController->Enable();
	leftController->SetSetpoint(leftSpeed);
	rightController->SetSetpoint(rightSpeed);
}

/**
 * Drive each motor independently at a speed given as a percentage of the
 * maximum speed.
 *
 * @param[in] leftSpeed The percentage for the left motor, from -1.0 to 1.0
 * @param[in] rightSpeed The percentage for the right motor, from -1.0 to 1.0
 *
 * @author William Kunkel
 * @author Nyle Rodgers
 */

// TODO: Figure out why values such as 1, -1 replaced for the speed * MAX_RPS 
//		makes drive backwards, but Cheesy Drive works
void Drive::setMotorsNormalized( float leftSpeed, float rightSpeed ) {
	leftController->Enable();
	rightController->Enable();
	leftController->SetSetpoint( leftSpeed * MAX_RPS );
	// The negative is to compensate for wiring
	rightController->SetSetpoint( -rightSpeed * MAX_RPS );
}

/**
 * Set both setpoints to 0.0
 *
 * @author William Kunkel
 */
void Drive::stop() {
	leftController->SetSetpoint(0.0);
	rightController->SetSetpoint(0.0);
}

void Drive::stopAndDisable() {
	leftController->SetSetpoint(0.0);
	rightController->SetSetpoint(0.0);
	leftController->Disable();
	rightController->Disable();
	rightMotor->Set(0.0);
	leftMotor->Set(0.0);
}

void Drive::resetEncoders() {
	leftEncoder->Reset();
	rightEncoder->Reset();
}

float Drive::getRotations() {
	return leftEncoder->GetDistance();
}

float Drive::getAmountSpun() {
	return fabs( leftEncoder->GetDistance() + rightEncoder->GetDistance() );
}

void Drive::setMotorsNormalizedDirect( float leftSpeed, float rightSpeed ) {
	leftController->SetSetpoint( 0.0 );
	rightController->SetSetpoint( 0.0 );
	leftController->Disable();
	rightController->Disable();
	leftMotor->Set( leftSpeed );
	rightMotor->Set( -rightSpeed );
}
