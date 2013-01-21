/**
 * @file Drive.cpp
 * @brief Implementation of the Drive subsystem
 * @author William Kunkel
 */

#include "Drive.h"
#include "../RobotMap.h"

// We need <math.h> for copysignf in cheesyDrive
#include <math.h>

// TODO: Tune PID and get accurate RPS numbers
const float Drive::P = 0.0,
            Drive::I = 0.0,
            Drive::D = 0.0;

const float Drive::MAX_RPS = 0.0;

const double Drive::ENCODER_RESOLUTION = 256.0;

const float Drive::MAX_PERCENT_ERROR = 1.0;

/**
 * Initialize the PID controllers for each side of the drive, and enable them,
 * with an initial setpoint of 0.0.
 *
 * @author William Kunkel
 */
Drive::Drive() : 
	Subsystem("Drive"),
	leftMotor( new Talon( DIGITAL_MODULE_PORT,
	                      LEFT_DRIVE_CHANNEL ) ),

	rightMotor( new Talon( DIGITAL_MODULE_PORT,
	                       RIGHT_DRIVE_CHANNEL ) ),

	leftEncoder( new Encoder( DIGITAL_MODULE_PORT,
	                          LEFT_DRIVE_ENCODER_CHANNEL_A,
	                          DIGITAL_MODULE_PORT,
	                          LEFT_DRIVE_ENCODER_CHANNEL_B ) ),

	rightEncoder( new Encoder( DIGITAL_MODULE_PORT,
	                           RIGHT_DRIVE_ENCODER_CHANNEL_A,
	                           DIGITAL_MODULE_PORT,
	                           RIGHT_DRIVE_ENCODER_CHANNEL_B ) ),

	// We need to use the encoders & talons to initialize this, so to be safe we
	// set it to a null pointer and assign in the constructor body.
	leftController(0),
	rightController(0) {

	leftController = new PIDController( P, I, D, leftEncoder, leftMotor );
	rightController = new PIDController( P, I, D, rightEncoder, rightMotor );

	leftEncoder->SetDistancePerPulse( 1 / ENCODER_RESOLUTION );
	rightEncoder->SetDistancePerPulse( 1 / ENCODER_RESOLUTION );

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

/** 
 * Set both motors to the same setpoint, causing the robot to drive forwards or
 * backwards in a straight line
 * 
 * @param[in] speed The speed at which to drive the motors, in rotations/second
 * 
 * @author William Kunkel
 */
void Drive::driveStraight( float speed ) {
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
 */
void Drive::setMotorsNormalized( float leftSpeed, float rightSpeed ) {
	leftController->SetSetpoint( leftSpeed * MAX_RPS );
	rightController->SetSetpoint( rightSpeed * MAX_RPS );
}

/**
 * Set both setpoints to 0.0
 *
 * @author William Kunkel
 */
void Drive::stop() {
	leftController->SetSetpoint(0.0);
	rightController->SetSetPoint(0.0);
}
