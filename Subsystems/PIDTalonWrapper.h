/**
* @file PIDTalonWrapper.h
* @brief Decleration of the Talon wrapper class for use with PID
* @author Nyle Rodgers
*/
#ifndef PIDTALONWRAPPER_H
#define PIDTALONWRAPPER_H

#include "WPILib.h"

/**
 * @brief the wrapper used to allow the PID controll to work with the tallons
 * 
 * This is to compensate for the fact that PID controll seems to have been 
 * writen to controll position of things rather than speed of things.
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
