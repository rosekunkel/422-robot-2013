#include "Pneumatics.h"
#include "../Robotmap.h"

Pneumatics::Pneumatics() : 
	Subsystem("Pneumatics"),
	diskPusher( new DoubleSolenoid( SOLENOID_MODULE_PORT,
		                                EXTEND_DISK_PUSHER_CHANNEL,
		                                RETRACT_DISK_PUSHER_CHANNEL ) ),
	compressor( new Compressor( DIGITAL_MODULE_PORT,
			                    COMPRESSOR_PRESSURE_SWITCH_CHANNEL,
			                    DIGITAL_MODULE_PORT,
			                    COMPRESSOR_RELAY_CHANNEL ) ) {
	compressor->Start();
	diskPusher->Set(DoubleSolenoid::kReverse);
}
    
void Pneumatics::InitDefaultCommand() {
	
}

/**
 * Extend the shooter's disk pusher solenoid.
 * 
 * @author Nyle Rodgers
 * @author William Kunkel
 */
void Pneumatics::extend() {
	diskPusher->Set(DoubleSolenoid::kForward);
}

/**
 * Retract the shooter's disk pusher solenoid.
 * 
 * @author Nyle Rodgers
 * @author William Kunkel
 */
void Pneumatics::retract() {
	diskPusher->Set(DoubleSolenoid::kReverse);
}
