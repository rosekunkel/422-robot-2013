#include "Nuke.h"

Nuke::Nuke() {
	Requires(nuclearOption);
	SetInterruptible(false);
	SetTimeout(0.3);
}

// Called just before this Command runs the first time
void Nuke::Execute() {
	nuclearOption->extend();
}

// Make this return true when this Command no longer needs to run execute()
bool Nuke::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void Nuke::End() {
	nuclearOption->retract();
}
