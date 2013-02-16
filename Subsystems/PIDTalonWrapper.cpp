/**
 * @file PIDTalonWrapper.cpp
 * @brief Implementation of the Talon wrapper class for use with PID
 * @author Nyle Rodgers
 */
#include "PIDTalonWrapper.h"

/**
 * Constructor for the PIDTalonWrapper class
 * 
 * @author Nyle Rodgers
 */
PIDTalonWrapper::PIDTalonWrapper(UINT8 moduleNumber, UINT32 channel):
	talon( new Talon( moduleNumber,
			          channel ) ){
	
}

/**
 * Sets the speed of the talon to value
 * 
 * @param[in] the speed to set the value to, from -1.0 to 1.0
 * 
 * @author Nyle Rodgers
 */
void PIDTalonWrapper::Set(float value) {
	talon->Set(value);
}

/**
 * Gets the speed that the talon is set to
 * 
 * @author Nyle Rodgers
 */
float PIDTalonWrapper::Get() {
	return talon->Get();
}

/**
 * Increment the speed of the talon by output, to be used by PID
 *
 * @param[in] output amount to increment the talon by
 *
 * @author Nyle Rodgers
 */
void PIDTalonWrapper::PIDWrite(float output) {
	float speed = talon->Get();
	speed += output;
	// Make sure that the speed we give the talon doesn'n exceed -1 to 1 range
	if (speed > 1.0) {
		speed = 1.0;
	} else if (speed < -1.0) {
		speed = -1.0;
	}
	talon->Set(speed);
}
