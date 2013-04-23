/**
 * @file ShooterArticulator.cpp
 * @brief Implementation of the Shooter articulator subsystem
 * @author Nyle Rodgers
 */

#include "ShooterArticulator.h"
#ifndef USE_PISTON_ARTICULATOR
#include <cmath>
#include "../Commands/OperateShooterArticulator.h"
#include "../RobotMap.h"

const float PI = 3.14159;

// TODO: Get accurate numbers for all measurements
const int ShooterArticulator::ENCODER_RESOLUTION = 64,
		  ShooterArticulator::ENCODER_GEAR_TEETH = 12,
		  ShooterArticulator::SCREW_GEAR_TEETH = 40;

// TODO: Measure real screw lead
const float ShooterArticulator::SCREW_LEAD = 1.0/16.0;

const float ShooterArticulator::DISTANCE_PER_TICK = 
	ShooterArticulator::SCREW_LEAD *
	ShooterArticulator::ENCODER_GEAR_TEETH /
	ShooterArticulator::SCREW_GEAR_TEETH /
	ShooterArticulator::ENCODER_RESOLUTION;


ShooterArticulator::ShooterArticulator() : 
	Subsystem("ShooterArticulator"),
	motor( new Talon( DIGITAL_MODULE_PORT,
			          ARTICULATOR_MOTOR_CHANNEL ) ),
	
	encoder( new Encoder( DIGITAL_MODULE_PORT,
	                      ARTICULATOR_ENCODER_CHANNEL_A,
	                      DIGITAL_MODULE_PORT,
	                      ARTICULATOR_ENCODER_CHANNEL_B,
	                      true,
	                      Encoder::k1X  ) ),
	topLimitSwitch( new DigitalInput( DIGITAL_MODULE_PORT,
			                          ARTICULATOR_TOP_LIMIT_SWITCH_CHANNEL ) ),
	bottomLimitSwitch( new DigitalInput( DIGITAL_MODULE_PORT,
			                             ARTICULATOR_BOTTOM_LIMIT_SWITCH_CHANNEL ) ),
	dashboard( DriverStationLCD::GetInstance() ) {
	encoder->SetDistancePerPulse( DISTANCE_PER_TICK );
	encoder->Start();
}
    
void ShooterArticulator::InitDefaultCommand() {
	SetDefaultCommand( new OperateShooterArticulator() );
}

/**
 * Move the acticulator up at full speed
 *
 * @author Nyle Rodgers
 */
void ShooterArticulator::moveUp() {
	if( topLimitSwitch->Get() ) {
		motor->Set(1.0);
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
		motor->Set(-1.0);
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

void ShooterArticulator::resetEncoder() {
	encoder->Reset();
}

double ShooterArticulator::getDisplacement() {
	return encoder->GetDistance();
}

#endif
