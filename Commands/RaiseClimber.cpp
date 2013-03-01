#include "RaiseClimber.h"

RaiseClimber::RaiseClimber() {
	Requires(climber);
}

void RaiseClimber::Initialize() {
	climber->raise();
}

bool RaiseClimber::IsFinished() {
	return true;
}
