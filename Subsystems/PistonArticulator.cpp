#include "PistonArticulator.h"
#ifdef USE_PISTON_ARTICULATOR
#include "../RobotMap.h"
#include "../Commands/OperateShooterArticulator.h"

PistonArticulator::PistonArticulator() :
	Subsystem("PistonArticulator"),
	articulator( new DoubleSolenoid( SOLENOID_MODULE_PORT,
		                             RAISE_SHOOTER_CHANNEL,
		                             LOWER_SHOOTER_CHANNEL ) ) {
	articulator->Set(DoubleSolenoid::kForward);
}

void PistonArticulator::InitDefaultCommand() {
	SetDefaultCommand( new OperateShooterArticulator() );
}

void PistonArticulator::raise() {
	articulator->Set(DoubleSolenoid::kForward);
}

void PistonArticulator::lower() {
	articulator->Set(DoubleSolenoid::kReverse);
}

#endif // USE_PISTON_ARTICULATOR
