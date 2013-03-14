#include "ControlLights.h"
#include "WPILib.h"
#include "../Subsystems/Lights.h"
#include "../OI.h"
// Called just before this Command runs the first time
ControlLights::ControlLights(Color whichLight) :
	light( whichLight ) {
	Requires(lights);
}
void ControlLights::Initialize() {
	if (light == RED) {
		lights->toggleRedLight();
	}
	else if (light == GREEN) {
		lights->toggleGreenLight();
	}
	else if (light == BLUE) {
		lights->toggleBlueLight();
	}	
}

// Make this return true when this Command no longer needs to run execute()
bool ControlLights::IsFinished() {
	return true;
}
