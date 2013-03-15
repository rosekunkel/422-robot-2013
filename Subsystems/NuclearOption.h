#ifndef NUCLEAR_OPTION_H
#define NUCLEAR_OPTION_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../CompilationSettings.h"

class NuclearOption: public Subsystem {
public:
	NuclearOption();
	void extend();
	void retract();
private:
	DoubleSolenoid *nuclearPiston;
};

#endif // NUCLEAR_OPTION_H
