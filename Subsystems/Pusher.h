/**
 * @file Pusher.h
 * @brief Declaration of the Pusher subsystem
 * @author Nyle Rodgers
 */
#ifndef PUSHER_H
#define PUSHER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../CompilationSettings.h"

/**
 * @brief The Pusher subsystem
 * 
 * Controls the disk pusher of the robot.
 */
class Pusher: public Subsystem {
public:
	/// Constructor for the pusher subsystem
	Pusher();

	/// Extend the disk pusher solenoid.
	void extend();

	/// Retract the disk pusher solenoid.
	void retract();
private:
	DoubleSolenoid *diskPusher;
};

#endif //PUSHER_H
