#ifndef ANTENNAE_H
#define ANTENNAE_H

#include "WPILib.h"
#include "Commands/Subsystem.h"

class Antennae : public Subsystem {
public:
	Antennae();
	bool get();
private:
	AnalogChannel *leftAntenna,
		          *rightAntenna;
};
#endif // ANTENNAE_H
