/**
 * @file Climber.h
 * @brief Declaration of the Climber subsystem
 * @author Nyle Rodgers
 */
#ifndef CLIMBER_H
#define CLIMBER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../CompilationSettings.h"

/**
 * @brief The Climber subsystem
 * 
 * Controls the climber of the robot.
 */
class Climber: public Subsystem {
public:
	/// constructor for the climber
	Climber();
	
	/// Toggle the climber
	void toggle();
private:
	Servo *rightServo, *leftServo;
	bool isRaised;
};

#endif //CLIMBER_H
