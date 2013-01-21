/**
 * @file Drive.h
 * @brief Declaration of the Drive subsystem
 * @author Ryan Lucia, David Clayton
 */
 
 #ifndef ARM_H
#define ARM_H

#include "WPILib.h"

/**
 * @brief The arm subclass.
 * 
 * Contains the arms.
 */
 
 class Arm{
 public:
	/// Constructor for the arm subsystem.
	Arm();
	
	/// Changes the angle.
	void turnMotor( float speed );

	/// Changes the winch extension.
	void runWinch( float speed );

private:
	Talon *motor, *winch;

};

#endif // ARM_H