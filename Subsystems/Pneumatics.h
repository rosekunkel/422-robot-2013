#ifndef PNEUMATICS_H
#define PNEUMATICS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Nyle
 */
class Pneumatics: public Subsystem {
public:
	Pneumatics();
	void InitDefaultCommand();
	
	/// Extend the disk pusher solenoid.
	void extend();

	/// Retract the disk pusher solenoid.
	void retract();
private:
	DoubleSolenoid *diskPusher;
	Compressor *compressor;
};

#endif //PNEUMATICS_H
