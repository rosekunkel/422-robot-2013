#include "PistonArticulator.h"
#ifdef USE_PISTON_ARTICULATOR
#include "../RobotMap.h"
#include "../Commands/OperateShooterArticulator.h"

PistonArticulator::PistonArticulator() :
	Subsystem("PistonArticulator"),
	articulator( new DoubleSolenoid( SOLENOID_MODULE_PORT,
		                             RAISE_SHOOTER_CHANNEL,
		                             LOWER_SHOOTER_CHANNEL ) ),
	isRaised( true ) {
	articulator->Set(DoubleSolenoid::kForward);
}

#ifndef PRIMARY_CONTROLS_ARTICULATOR
void PistonArticulator::InitDefaultCommand() {
	SetDefaultCommand( new OperateShooterArticulator() );
}
#endif

void PistonArticulator::raise() {
	articulator->Set(DoubleSolenoid::kForward);
	isRaised = true;
}

void PistonArticulator::lower() {
	articulator->Set(DoubleSolenoid::kReverse);
	isRaised = false;
}

void PistonArticulator::toggle() {
	if( isRaised ) {
		lower();
	}
	else {
		raise();
	}
}
#endif // USE_PISTON_ARTICULATOR
