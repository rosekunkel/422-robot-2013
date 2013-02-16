#include "Shoot.h"

Shoot::Shoot() {
	Requires(pneumatics);
	SetInterruptible(false);
	SetTimeout(0.5);
}

// Called just before this Command runs the first time
void Shoot::Initialize() {
	pneumatics->extend();
}

// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void Shoot::End() {
	pneumatics->retract();
}
