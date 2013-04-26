#include "Flashlight.h"
#include "../RobotMap.h"

Flashlight::Flashlight() :
	Subsystem("Flashlight"),
	flashlight( new Talon( DIGITAL_MODULE_PORT,
		                   FLASHLIGHT_CHANNEL  ) ),
	isOn( false ) {
	flashlight->Set( 0.0 );
}

void Flashlight::turnOn() {
	isOn = true;
	flashlight->Set(1.0);
}

void Flashlight::turnOff() {
	isOn = false;
	flashlight->Set(0.0);
}

void Flashlight::toggle() {
	if( isOn ) {
		turnOff();
	}
	else {
		turnOn();
	}
}
