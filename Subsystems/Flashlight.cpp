#include "Flashlight.h"
#include "../RobotMap.h"

Flashlight::Flashlight() :
	Subsystem("Flashlight"),
	flashlight( new Servo( DIGITAL_MODULE_PORT,
		                   FLASHLIGHT_CHANNEL  ) ) {
	flashlight->Set( 0.0 );
}
