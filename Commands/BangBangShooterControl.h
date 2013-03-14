#ifndef BANG_BANG_SHOOTER_CONTROL_H
#define BANG_BANG_SHOOTER_CONTROL_H

#include "../CompilationSettings.h"
#ifdef USE_BANG_BANG

#include "../CommandBase.h"

/**
 *
 *
 * @author Nyle
 */
class BangBangShooterControl: public CommandBase {
public:
	BangBangShooterControl();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	float firstWheelSetpoint,
	      secondWheelSetpoint;
	DriverStationLCD *dashboard;
};

#endif
#endif
