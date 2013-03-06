/**
 * @file Climber.cpp
 * @brief Implementation of the climber subsystem
 * @author Nyle Rodgers
 */
#include "Climber.h"
#include "../RobotMap.h"

Climber::Climber() : 
	Subsystem("Climber"),
	rightServo( new Servo( DIGITAL_MODULE_PORT,
			               CLIMBER_RIGHT_SERVO_CHANNEL) ),
	leftServo( new Servo( DIGITAL_MODULE_PORT,
						   CLIMBER_LEFT_SERVO_CHANNEL) ) {
	rightServo->Set(0.0);
	leftServo->Set(1.0);
	isRaised = false;
}

/**
 * Raise the climber.
 * 
 * @author Nyle Rodgers
 */
void Climber::raise() {
	rightServo->Set(0.5);
	leftServo->Set(0.5);
	isRaised = true;
}

/**
 * Lower the climber.
 * 
 * @author Nyle Rodgers
 */
void Climber::lower() {
	rightServo->Set(0.0);
	leftServo->Set(1.0);
	isRaised = false;
}

void Climber::toggle() {
	if( isRaised ) {
		lower();
	}
	else {
		raise();
	}
}
