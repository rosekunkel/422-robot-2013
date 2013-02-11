#include "PIDTalonWrapper.h"

PIDTalonWrapper::PIDTalonWrapper(UINT8 moduleNumber, UINT32 channel):
	talon( new Talon( moduleNumber,
			          channel ) ){
	
}

void PIDTalonWrapper::Set(float value) {
	talon->Set(value);
}
    
void PIDTalonWrapper::PIDWrite(float output) {
	float speed = talon->Get();
	speed += output;
	if (speed > 1.0) {
		speed = 1.0;
	} else if (speed < -1.0) {
		speed = -1.0;
	}
	talon->Set(speed);
}
