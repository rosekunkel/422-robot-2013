#include "Antennae.h"
#include "../RobotMap.h"

Antennae::Antennae() :
	Subsystem( "Antennae" ),
	leftAntenna( new AnalogChannel( ANALOG_MODULE_PORT, LEFT_ANTENNA_CHANNEL ) ),
	rightAntenna( new AnalogChannel( ANALOG_MODULE_PORT, RIGHT_ANTENNA_CHANNEL ) ) {
}

bool Antennae::get() {
	return leftAntenna->GetAverageVoltage() > 2.5
		&& rightAntenna->GetAverageVoltage() > 2.5;
}
