#include "ToggleFlashlight.h"

ToggleFlashlight::ToggleFlashlight() {
	Requires( flashlight );
}

// Called just before this Command runs the first time
void ToggleFlashlight::Initialize() {
	flashlight->toggle();
}


// Make this return true when this Command no longer needs to run execute()
bool ToggleFlashlight::IsFinished() {
	return true;
}
