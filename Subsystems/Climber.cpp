/**
 * @file Climber.cpp
 * @brief Implementation of the climber subsystem
 * @author Nyle Rodgers
 */
#include "Climber.h"
#include "../Robotmap.h"

Climber::Climber() : 
	Subsystem("Climber"),
	rightServo( new Servo( DIGITAL_MODULE_PORT,
			               CLIMBER_RIGHT_SERVO_CHANNEL) ),
	leftServo( new Servo( DIGITAL_MODULE_PORT,
						   CLIMBER_LEFT_SERVO_CHANNEL) ) {
	rightServo->Set(0.0);
	leftServo->Set(0.0);
}

/**
 * Raise the climber. This is a one way operation, it can't be raised after
 * 
 * @author Nyle Rodgers
 */
void Climber::raise() {
	rightServo->Set(0.5);
	leftServo->Set(0.5);
}
