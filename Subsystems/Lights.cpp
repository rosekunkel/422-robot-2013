/**
 * @file Lights.cpp
 * @brief Implementation of the LED subsystem
 * @author Lucario
 */
#include "Lights.h"
#include "Relay.h"
#include "../Robotmap.h"

Lights::Lights() : 
	Subsystem("Lights"),
	redLight( new Relay( RED_RELAY_CHANNEL,
			                        Relay::kForwardOnly ) ),
	blueLight( new Relay( BLUE_RELAY_CHANNEL,
			                        Relay::kForwardOnly ) ),
	greenLight( new Relay( GREEN_RELAY_CHANNEL,
			                        Relay::kForwardOnly ) ){
	redLight->Set(Relay::kOn);
	blueLight->Set(Relay::kOn);
	greenLight->Set(Relay::kOn);
	} 
void Lights::toggleRedLight() {
	if (redLight->Get()) {
	redLight->Set(Relay::kOff);
	} else {
	redLight->Set(Relay::kOn);
	}
}	
void Lights::toggleBlueLight() {
	if (blueLight->Get()) {
	blueLight->Set(Relay::kOff);
	} else {
	blueLight->Set(Relay::kOn);
	}
}	
void Lights::toggleGreenLight() {
	if (greenLight->Get()) {
	greenLight->Set(Relay::kOff);
	} else {
	greenLight->Set(Relay::kOn);
	}
}	
