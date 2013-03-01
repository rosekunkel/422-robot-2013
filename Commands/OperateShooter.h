#ifndef OPERATESHOOTER_H
#define OPERATESHOOTER_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Nyle
 */
class OperateShooter: public CommandBase {
public:
	OperateShooter();
	virtual void Initialize() {};
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End() {};
	virtual void Interrupted() {};
private:
	DriverStationLCD *dashboard;
};

#endif
