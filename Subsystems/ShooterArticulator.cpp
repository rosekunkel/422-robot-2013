/**
 * @file ShooterArticulator.cpp
 * @brief Implementation of the Shooter articulator subsystem
 * @author Nyle Rodgers
 */
#include "ShooterArticulator.h"
#include "../Robotmap.h"

// TODO: put actual numbers in here
const float ShooterArticulator::ZERO_DEGREE_VOLTAGE = 0;
const float ShooterArticulator::ONE_EIGHTY_DEGREE_VOLTAGE = 1;


ShooterArticulator::ShooterArticulator() : 
	Subsystem("ShooterArticulator"),
	motor( new Talon( DIGITAL_MODULE_PORT,
			          ARTICULATOR_MOTOR_CHANNEL) ),
	
	potentiometer( new AnalogChannel( DIGITAL_MODULE_PORT,
			                          ARTICULATOR_POTENTIOMETER_CHANNEL ) ) {
	
}
    
void ShooterArticulator::InitDefaultCommand() {
	
}

/**
 * Get the current angle, in degrees, above horizontal
 *
 * @author Nyle Rodgers
 */ 
double ShooterArticulator::getAngle() {
	return ( ( potentiometer->GetAverageVoltage() - ZERO_DEGREE_VOLTAGE) 
			   / ONE_EIGHTY_DEGREE_VOLTAGE ) * 180.0;
}

/**
 * Move the acticulator up at full speed
 *
 * @author Nyle Rodgers
 */
void ShooterArticulator::moveUp() {
	motor->Set(1.0);
}

/**
 * Move the articulator down at full speed
 *
 * @author Nyle Rodgers
 */
void ShooterArticulator::moveDown() {
	motor->Set(-1.0);
}

/**
 * Stop moving the articulator
 *
 * @author Nyle Rodgers
 */
void ShooterArticulator::stop() {
	motor->Set(0.0);
}
