#include "ToggleArticulator.h"

#ifdef USE_PISTON_ARTICULATOR
#ifdef PRIMARY_CONTROLS_ARTICULATOR
ToggleArticulator::ToggleArticulator() {
	Requires( pistonArticulator );
}

// Called just before this Command runs the first time
void ToggleArticulator::Initialize() {
	pistonArticulator->toggle();
}


// Make this return true when this Command no longer needs to run execute()
bool ToggleArticulator::IsFinished() {
	return true;
}
#endif
#endif
