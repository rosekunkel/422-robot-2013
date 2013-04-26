#ifndef PISTON_ARTICULATOR_H
#define PISTON_ARTICULATOR_H


#include "WPILib.h"
#include "Commands/Subsystem.h"
#include "../CompilationSettings.h"
#ifdef USE_PISTON_ARTICULATOR

class PistonArticulator : public Subsystem {
public:
	PistonArticulator();
#ifndef PRIMARY_CONTROLS_ARTICULATOR
	void InitDefaultCommand();
#endif
	void raise();
	void lower();
	void toggle();
private:
	DoubleSolenoid *articulator;
	bool isRaised;
};

#endif // USE_PISTON_ARTICULATOR
#endif // PISTON_ARTICULATOR_H
