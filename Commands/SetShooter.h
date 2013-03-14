#ifndef SET_SHOOTER_H
#define SET_SHOOTER_H

#include "WPILib.h"
#include "../CommandBase.h"

class SetShooter : public CommandBase {
public:
	SetShooter( float setpoint );
	void Initialize();
	void Execute() {}
	bool IsFinished();
	void End() {}
	void Interrupted() {}
private:
	float setpoint;
};
#endif // SET_SHOOTER_H
