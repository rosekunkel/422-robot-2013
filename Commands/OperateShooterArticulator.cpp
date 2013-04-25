#include "OperateShooterArticulator.h"
#ifndef PRIMARY_CONTROLS_ARTICULATOR
#include "../RobotMap.h"

OperateShooterArticulator::OperateShooterArticulator() {
#ifdef USE_PISTON_ARTICULATOR
	Requires(pistonArticulator);
#else
	Requires(shooterArticulator);
#endif
}

// Called repeatedly when this Command is scheduled to run
void OperateShooterArticulator::Execute() {
#ifdef USE_GAMECUBE_CONTROLLER
	// The gamecube controller maps from 0.75 to -0.75, we need to adjust
	float y = operatorInterface
			  ->getSecondaryJoystick()
			  ->GetRawAxis(GC_LEFT_Y) * (-4/3);
#else
	float y = operatorInterface->getSecondaryJoystick()->GetY();
#endif
	if (y > 0.5) {
#ifdef USE_PISTON_ARTICULATOR
		pistonArticulator->raise();
#else
		shooterArticulator->moveUp();
#endif
	}
	else if (y < -0.5) {
#ifdef USE_PISTON_ARTICULATOR
		pistonArticulator->lower();
#else
		shooterArticulator->moveDown();
#endif
	}
#ifndef USE_PISTON_ARTICULATOR
	else {
		shooterArticulator->stop();
	}
#endif
}

// Make this return true when this Command no longer needs to run execute()
bool OperateShooterArticulator::IsFinished() {
	return false;
}
#endif
