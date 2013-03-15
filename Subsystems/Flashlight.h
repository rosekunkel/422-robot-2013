#ifndef FLASHLIGHT_H
#define FLASHLIGHT_H

#include "WPILib.h"
#include "Commands/Subsystem.h"
#include "../CompilationSettings.h"

class Flashlight : public Subsystem {
public:
	Flashlight();
private:
	Servo *flashlight;
};

#endif // FLASHLIGHT_H
