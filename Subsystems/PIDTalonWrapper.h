#ifndef PIDTALONWRAPPER_H
#define PIDTALONWRAPPER_H

#include "WPILib.h"

/**
 *
 *
 * @author Nyle
 */
class PIDTalonWrapper: public PIDOutput {
private:
	Talon *talon;
public:
	void Set(float value);
	PIDTalonWrapper(UINT8 moduleNumber, UINT32 channel);
	virtual void PIDWrite(float output);
};

#endif
