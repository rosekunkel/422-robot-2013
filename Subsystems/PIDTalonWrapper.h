/**
* @file PIDTalonWrapper.h
* @brief Decleration of the Talon wrapper class for use with PID
* @author Nyle Rodgers
*/
#ifndef PIDTALONWRAPPER_H
#define PIDTALONWRAPPER_H

#include "WPILib.h"
#include "../CompilationSettings.h"

/**
 * @brief the wrapper used to allow the PID control to work with the tallons
 * 
 * This is to compensate for the fact that PID control seems to have been 
 * writen to control position of things rather than speed of things.
 *
 * @author Nyle
 */
class PIDTalonWrapper: public PIDOutput {
private:
	Talon *talon;
public:
	/// Constructor for the PIDTalonWrapper class
	PIDTalonWrapper(UINT8 moduleNumber, UINT32 channel);
	
	/// Set the speed of the talon to value
	void Set(float value);
	
	float Get();
	
	/// Increments the speed of the talon by output
	virtual void PIDWrite(float output);
};

#endif //PIDTALONWRAPPER_H
