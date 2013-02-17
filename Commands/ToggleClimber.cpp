#include "ToggleClimber.h"

ToggleClimber::ToggleClimber() {
	Requires(climber);
}

// Called just before this Command runs the first time
void ToggleClimber::Initialize() {
	climber->toggle();
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleClimber::IsFinished() {
	return true;
}
