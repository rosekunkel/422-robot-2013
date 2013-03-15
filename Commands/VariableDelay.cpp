#include "VariableDelay.h"

const float VariableDelay::SCALING_FACTOR = 5.0;

VariableDelay::VariableDelay() {
	Requires(shooter);
	Requires(variableDial);
	SetInterruptible(false);
}

void VariableDelay::Initialize() {
	float delay = variableDial->getNormalized() * SCALING_FACTOR;
	if( delay < 0.0 ) {
		SetTimeout( 0.0 );
	}
	else {
		SetTimeout( delay );
	}
}

bool VariableDelay::IsFinished() {
	return IsTimedOut();
}
