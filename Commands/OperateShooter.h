#ifndef OPERATE_SHOOTER_H
#define OPERATE_SHOOTER_H

#include "../CompilationSettings.h"
#ifndef USE_BANG_BANG

#include "../CommandBase.h"

class OperateShooter: public CommandBase {
public:
	OperateShooter();
	void Initialize() {}
	void Execute();
	bool IsFinished();
	void End() {}
	void Interrupted() {}
private:
	DriverStationLCD *dashboard;
	bool isIncreaseButtonPressed,
		 isDecreaseButtonPressed;
	float leftSetpoint,
		  rightSetpoint;
};

#endif
#endif
