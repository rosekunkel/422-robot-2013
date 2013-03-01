#include "ControlLights.h"
#include "WPILib.h"
#include "../Subsystems/Lights.h"
#include "../OI.h"
// Called just before this Command runs the first time
ControlLights::ControlLights(int whichLight) {
	light = whichLight;
}
void ControlLights::Initialize() {
	Requires(lights);
	
	if (light == 0) {
		lights->toggleRedLight();
	}	else if (light == 1) {
		lights->toggleBlueLight();
	}	else if (light == 2) {
		lights->toggleGreenLight();
	}	
}

// Called repeatedly when this Command is scheduled to run
void ControlLights::Execute() {	

}

// Make this return true when this Command no longer needs to run execute()
bool ControlLights::IsFinished() {
	return true;
}
