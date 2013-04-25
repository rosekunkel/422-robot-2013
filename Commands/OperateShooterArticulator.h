#ifndef OPERATE_SHOOTER_ARTICULATOR_H
#define OPERATE_SHOOTER_ARTICULATOR_H

#include "../CommandBase.h"
#include "../CompilationSettings.h"
#ifndef PRIMARY_CONTROLS_ARTICULATOR

class OperateShooterArticulator: public CommandBase {
public:
	OperateShooterArticulator();
	void Initialize() {}
	void Execute();
	bool IsFinished();
	void End() {}
	void Interrupted() {}
};
#endif
#endif
