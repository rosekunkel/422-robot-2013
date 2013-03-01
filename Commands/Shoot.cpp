#include "Shoot.h"

Shoot::Shoot() {
	Requires(pusher);
	SetInterruptible(false);
	isFired = false;
	SetTimeout(0.1);
}

// Called just before this Command runs the first time
void Shoot::Execute() {
	pusher->extend();
}

// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void Shoot::End() {
	pusher->retract();
}
