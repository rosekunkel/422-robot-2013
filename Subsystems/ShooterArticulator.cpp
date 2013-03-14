/**
 * @file ShooterArticulator.cpp
 * @brief Implementation of the Shooter articulator subsystem
 * @author Nyle Rodgers
 */
#define _USE_MATH_DEFINES
#include <cmath>

#include "ShooterArticulator.h"
#include "../Commands/OperateShooterArticulator.h"
#include "../RobotMap.h"

const float PI = 3.14159;

// TODO: Get accurate numbers for all measurements
const float ShooterArticulator::ENCODER_RESOLUTION = 64;
const float ShooterArticulator::DISTANCE_PER_REVOLUTION = 0.5; // in inches
const float ShooterArticulator::BASE_LENGTH = 24.0; // in inches
const float ShooterArticulator::SHOOTER_LENGTH = 28.0; // in inches
const float ShooterArticulator::ARTICULATOR_MOUNT_LENGTH = 2.0; // in inches
const float ShooterArticulator::ARTICULATOR_SHAFT_ZERO = 10.0; // in inches
const float ShooterArticulator::STARTING_DISTANCE = 0.0;

ShooterArticulator::ShooterArticulator() : 
	Subsystem("ShooterArticulator"),
	motor( new Talon( DIGITAL_MODULE_PORT,
			          ARTICULATOR_MOTOR_CHANNEL ) ),
	
	encoder( new Encoder( DIGITAL_MODULE_PORT,
	                      ARTICULATOR_ENCODER_CHANNEL_A,
	                      DIGITAL_MODULE_PORT,
	                      ARTICULATOR_ENCODER_CHANNEL_B,
	                      false,
	                      Encoder::k1X  ) ),
	topLimitSwitch( new DigitalInput( DIGITAL_MODULE_PORT,
			                          ARTICULATOR_TOP_LIMIT_SWITCH_CHANNEL ) ),
	bottomLimitSwitch( new DigitalInput( DIGITAL_MODULE_PORT,
			                             ARTICULATOR_BOTTOM_LIMIT_SWITCH_CHANNEL ) ),
	dashboard( DriverStationLCD::GetInstance() ) {
	encoder->SetDistancePerPulse( DISTANCE_PER_REVOLUTION / ENCODER_RESOLUTION );
	encoder->Start();
}
    
void ShooterArticulator::InitDefaultCommand() {
	SetDefaultCommand( new OperateShooterArticulator() );
}

/**
 * Get the current angle, in radians, above horizontal
 *
 * @author Nyle Rodgers
 */ 
double ShooterArticulator::getAngle() {
	return acos( ( pow( BASE_LENGTH, 2.0 )
			       + pow( SHOOTER_LENGTH, 2.0 )
			       - ( pow( encoder->GetDistance() + ARTICULATOR_SHAFT_ZERO, 2.0 ) 
			           + pow( ARTICULATOR_MOUNT_LENGTH, 2.0 ) ) )
			     / ( 2 * BASE_LENGTH * SHOOTER_LENGTH ) );
}

/**
 * Move the acticulator up at full speed
 *
 * @author Nyle Rodgers
 */
void ShooterArticulator::moveUp() {
	if( topLimitSwitch->Get() ) {
		motor->Set(-1.0);
		float distance = STARTING_DISTANCE + encoder->GetDistance();
		dashboard->PrintfLine( DriverStationLCD::kUser_Line6, "SA: %g", distance );
		dashboard->UpdateLCD();
	}
	else {
		stop();
	}
}

/**
 * Move the articulator down at full speed
 *
 * @author Nyle Rodgers
 */
void ShooterArticulator::moveDown() {
	if( bottomLimitSwitch->Get() ) {
		motor->Set(1.0);
		float distance = STARTING_DISTANCE + encoder->GetDistance();
		dashboard->PrintfLine( DriverStationLCD::kUser_Line6, "SA: %g", distance );
		dashboard->UpdateLCD();
	}
	else {
		stop();
	}
}

/**
 * Stop moving the articulator
 *
 * @author Nyle Rodgers
 */
void ShooterArticulator::stop() {
	motor->Set(0.0);
}
