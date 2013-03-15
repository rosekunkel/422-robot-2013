#include "VariableDial.h"
#include "../RobotMap.h"

// TODO: Confirm these values
const float VariableDial::MINIMUM_VOLTAGE = 0.0;
const float VariableDial::MAXIMUM_VOLTAGE = 5.0;

VariableDial::VariableDial() :
	Subsystem("Variable Dial"),
	potentiometer( new AnalogChannel( ANALOG_MODULE_PORT,
		                              VARIABLE_DIAL_CHANNEL ) ) {
}

float VariableDial::get() {
	return potentiometer->GetAverageVoltage();
}

float VariableDial::getNormalized() {
	float voltage = potentiometer->GetAverageVoltage();
	return (voltage - MINIMUM_VOLTAGE) / (MAXIMUM_VOLTAGE - MINIMUM_VOLTAGE);
}
