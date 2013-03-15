#include "NuclearOption.h"
#include "../RobotMap.h"

NuclearOption::NuclearOption() : 
	Subsystem("Nuclear Option"),
	nuclearPiston( new DoubleSolenoid( SOLENOID_MODULE_PORT,
			                           EXTEND_NUCLEAR_OPTION_CHANNEL,
			                           RETRACT_NUCLEAR_OPTION_CHANNEL ) ) {
	nuclearPiston->Set(DoubleSolenoid::kReverse);
	
}

void NuclearOption::extend() {
	nuclearPiston->Set(DoubleSolenoid::kForward);
}

void NuclearOption::retract() {
	nuclearPiston->Set(DoubleSolenoid::kReverse);
}
