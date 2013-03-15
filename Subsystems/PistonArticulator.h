#ifndef PISTON_ARTICULATOR_H
#define PISTON_ARTICULATOR_H


#include "WPILib.h"
#include "Commands/Subsystem.h"
#include "../CompilationSettings.h"
#ifdef USE_PISTON_ARTICULATOR

class PistonArticulator : public Subsystem {
public:
	PistonArticulator();
	void InitDefaultCommand();
	void raise();
	void lower();
private:
	DoubleSolenoid *articulator;
};

#endif // USE_PISTON_ARTICULATOR
#endif // PISTON_ARTICULATOR_H
