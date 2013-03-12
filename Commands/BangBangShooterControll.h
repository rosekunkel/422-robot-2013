#ifndef BANGBANGSHOOTERCONTROLL_H
#define BANGBANGSHOOTERCONTROLL_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Nyle
 */
class BangBangShooterControll: public CommandBase {
public:
	BangBangShooterControll();
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
