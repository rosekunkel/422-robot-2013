#ifndef FLASHLIGHT_H
#define FLASHLIGHT_H

#include "WPILib.h"
#include "Commands/Subsystem.h"
#include "../CompilationSettings.h"

class Flashlight : public Subsystem {
public:
	Flashlight();
	void turnOn();
	void turnOff();
	void toggle();
private:
	Talon *flashlight;
	bool isOn;
};

#endif // FLASHLIGHT_H
