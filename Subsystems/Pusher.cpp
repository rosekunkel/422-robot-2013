/**
 * @file Pusher.cpp
 * @brief Implementation of the Pusher subsystem
 * @author Nyle Rodgers
 */
#include "Pusher.h"
#include "../Robotmap.h"

Pusher::Pusher() : 
	Subsystem("Pusher"),
	diskPusher( new DoubleSolenoid( SOLENOID_MODULE_PORT,
			                        EXTEND_DISK_PUSHER_CHANNEL,
			                        RETRACT_DISK_PUSHER_CHANNEL ) ) {
	diskPusher->Set(DoubleSolenoid::kReverse);
	
}

/**
 * Extend the shooter's disk pusher solenoid.
 * 
 * @author Nyle Rodgers
 * @author William Kunkel
 */
void Pusher::extend() {
	diskPusher->Set(DoubleSolenoid::kForward);
}

/**
 * Retract the shooter's disk pusher solenoid.
 * 
 * @author Nyle Rodgers
 * @author William Kunkel
 */
void Pusher::retract() {
	diskPusher->Set(DoubleSolenoid::kReverse);
}
