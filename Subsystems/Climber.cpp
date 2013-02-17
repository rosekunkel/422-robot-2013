/**
 * @file Climber.cpp
 * @brief Implementation of the climber subsystem
 * @author Nyle Rodgers
 */
#include "Climber.h"
#include "../Robotmap.h"

Climber::Climber() : 
	Subsystem("Climber"),
	solenoid( new DoubleSolenoid( SOLENOID_MODULE_PORT,
		                          LOWER_CLIMBER_CHANNEL,
		                          RAISE_CLIMBER_CHANNEL) ){
	solenoid->Set(DoubleSolenoid::kForward);
	isRaised = false;
}

/**
 * Raise the climber.
 * 
 * @author Nyle Rodgers
 */
void Climber::raise() {
	solenoid->Set(DoubleSolenoid::kReverse);
	isRaised = true;
}

/**
 * Lower the climber.
 * 
 * @author Nyle Rodgers
 */
void Climber::lower() {
	solenoid->Set(DoubleSolenoid::kForward);
	isRaised = false;
}

void Climber::toggle() {
	if( isRaised ) {
		lower();
	} else {
		raise();
	}
}
