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
	leftMotor( new Talon( ROBOT_MAP.DIGITAL_MODULE_PORT,
	                      ROBOT_MAP.LEFT_DRIVE_CHANNEL ) ),

	rightMotor( new Talon( ROBOT_MAP.DIGITAL_MODULE_PORT,
	                       ROBOT_MAP.RIGHT_DRIVE_CHANNEL ) ),

	leftEncoder( new Encoder( ROBOT_MAP.DIGITAL_MODULE_PORT,
	                          ROBOT_MAP.LEFT_DRIVE_ENCODER_CHANNEL_A,
	                          ROBOT_MAP.DIGITAL_MODULE_PORT,
	                          ROBOT_MAP.LEFT_DRIVE_ENCODER_CHANNEL_B ) ),

	rightEncoder( new Encoder( ROBOT_MAP.DIGITAL_MODULE_PORT,
	                           ROBOT_MAP.RIGHT_DRIVE_ENCODER_CHANNEL_A,
	                           ROBOT_MAP.DIGITAL_MODULE_PORT,
	                           ROBOT_MAP.RIGHT_DRIVE_ENCODER_CHANNEL_B ) ),

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
 * Drive the robot using "Cheesy Drive", where one of the joysticks controls
 * forward-and-back motion and the other controls turning.
 * 
 * @param[in] linearStick The joystick which controls forward-and-back motion
 * @param[in] turningStick The joystick which controls turning motion
 * @note The joysticks may be the same joystick
 *
 * @author William Kunkel
 */
void Drive::cheesyDrive( Joystick *linearStick, Joystick *turningStick ) {
	float forward = linearStick->GetY();
	float turning = turningStick->GetX();

	// We determine the speed multiplier by adding and subtracting the turning
	// value from the base speed
	float leftMultiplier = forward+turning,
	      rightMultiplier = forward-turning;
	
	// We need to make sure that our speed multiplier does not exceed 100%, but
	// simple scaling between -2 and 2 would limit linear top speed.	
	if( ( leftMultiplier > 1 )
	 || ( leftMultiplier < -1 ) ) {
		// We set the multiplier to +-100%, based on it's original sign
		leftMultiplier = copysignf( 1.0, leftMultiplier );
	}

	// Repeat with the right multiplier
	if( ( rightMultiplier > 1 )
	 || ( rightMultiplier < -1 ) ) {
		rightMultiplier = copysignf( 1.0, rightMultiplier );
	}

	// Set the speed, using the multiplier as a percentage of the top speed
	leftController->SetSetpoint( leftMultiplier * MAX_RPS );
	rightController->SetSetpoint( rightMultiplier * MAX_RPS );
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
