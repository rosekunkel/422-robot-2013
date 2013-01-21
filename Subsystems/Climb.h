/**
 * @file Drive.h
 * @brief Declaration of the Drive subsystem
 * @author Ryan Lucia
 */

#ifndef CLIMB_H
#define CLIMB_H

#include "WPILib.h"
#include "Arm.h"

/**
 * @brief The Climb subsystem
 * 
 * Controls the climbing arms of the robot.
 */
class Climb: public Subsystem {
public:
	/// Constructor for the Climb subsystem.
	Climb();
	
	//TODO: Fill in this crap (crap = controls) because we need it. 

private:
	Arm *arm0, *arm1
};

#endif // CLIMB_H