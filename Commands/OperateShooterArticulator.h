#ifndef OPERATESHOOTERARTICULATOR_H
#define OPERATESHOOTERARTICULATOR_H

#include "../CommandBase.h"
#include "../CompilationSettings.h"

/**
 *
 *
 * @author Nyle
 */
class OperateShooterArticulator: public CommandBase {
public:
	OperateShooterArticulator();
	virtual void Initialize() {};
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End() {};
	virtual void Interrupted() {};
};

#endif
