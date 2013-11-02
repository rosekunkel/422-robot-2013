/**
 * @file Lights.cpp
 * @brief Implementation of the LED subsystem
 * @author Alan
 */
#include "Lights.h"
#include "Relay.h"
#include "../RobotMap.h"

Lights::Lights() : 
	Subsystem("Lights"),
	redLight( new Relay( RED_RELAY_CHANNEL,
	                     Relay::kForwardOnly ) ),
	greenLight( new Relay( GREEN_RELAY_CHANNEL,
			              Relay::kForwardOnly ) ),
	blueLight( new Relay( BLUE_RELAY_CHANNEL,
			               Relay::kForwardOnly ) ){
	redLight->Set(Relay::kOff);
	greenLight->Set(Relay::kOff);
	blueLight->Set(Relay::kOff);
}
 
void Lights::toggleRedLight() {
	if( redLight->Get() == Relay::kOn ) {
		redLight->Set(Relay::kOff);
	}
	else {
		redLight->Set(Relay::kOn);
	}
}

void Lights::toggleGreenLight() {
	if( greenLight->Get() == Relay::kOn ) {
		greenLight->Set(Relay::kOff);
	}
	else {
		greenLight->Set(Relay::kOn);
	}
}
	
void Lights::toggleBlueLight() {
	if( blueLight->Get() == Relay::kOn ) {
		blueLight->Set(Relay::kOff);
	}
	else {
		blueLight->Set(Relay::kOn);
	}
}

void Lights::turnOnRedLight() {
	redLight->Set(Relay::kOn);
}

void Lights::turnOnGreenLight() {
	greenLight->Set(Relay::kOn);
}

void Lights::turnOnBlueLight() {
	blueLight->Set(Relay::kOn);
}

void Lights::turnOffRedLight() {
	redLight->Set(Relay::kOff);
}

void Lights::turnOffGreenLight() {
	greenLight->Set(Relay::kOff);
}

void Lights::turnOffBlueLight() {
	blueLight->Set(Relay::kOff);
}
