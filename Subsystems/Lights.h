/**
 * @file Lights.h
 * @brief Declaration of the LED subsystem
 * @author Alan
 */
#ifndef LIGHTS_H
#define LIGHTS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../CompilationSettings.h"

/**
 * @brief The Lights subsystem
 * 
 * Controls the LED's on the bottom of the robot.
 */
class Lights: public Subsystem {
public:
	/// Constructor for the Lights
	Lights();

	/// Turn the lights on
	void toggleRedLight();
	void toggleGreenLight();
	void toggleBlueLight();

	/// Turn the Light off.
	void turnLightOff();
private:
	Relay *redLight;
	Relay *greenLight;
	Relay *blueLight;
};

#endif //LIGHTS_H
