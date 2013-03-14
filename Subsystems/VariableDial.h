#ifndef VARIABLE_DIAL_H
#define VARIABLE_DIAL_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../CompilationSettings.h"

class VariableDial : public Subsystem {
public:
	VariableDial();
	float get();
	float getNormalized();
private:
	AnalogChannel *potentiometer;
	static const float MINIMUM_VOLTAGE,
		               MAXIMUM_VOLTAGE;
};

#endif
