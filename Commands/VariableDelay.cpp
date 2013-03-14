#include "VariableDelay.h"

const float VariableDelay::SCALING_FACTOR = 1.0;

VariableDelay::VariableDelay() {
	Requires(shooter);
	Requires(variableDial);
	SetInterruptible(false);
}

void VariableDelay::Initialize() {
	SetTimeout( variableDial->getNormalized() * SCALING_FACTOR );
}

bool VariableDelay::IsFinished() {
	return IsTimedOut();
}
