#include "ControlLights.h"
#include "WPILib.h"
#include "../Subsystems/Lights.h"
#include "../OI.h"
// Called just before this Command runs the first time
void ControlLights::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void ControlLights::Execute() {	
	Requires(lights);
	if (operatorInterface->getToggleRedButtonValue()) {
	lights->toggleRedLight();
	}	
	if (operatorInterface->getToggleBlueButtonValue()) {
	lights->toggleBlueLight();
	}	
	if (operatorInterface->getToggleGreenButtonValue()) {
	lights->toggleGreenLight();
	}	
}

// Make this return true when this Command no longer needs to run execute()
bool ControlLights::IsFinished() {
	return false;
}
