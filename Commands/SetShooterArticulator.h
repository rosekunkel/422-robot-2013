#ifndef SETSHOOTERARTICULATOR_H
#define SETSHOOTERARTICULATOR_H

#include "../CommandBase.h"
#include "../CompilationSettings.h"

/**
 *
 *
 * @author Nyle
 */
class SetShooterArticulator: public CommandBase {
public:
	/// angle is in radians
	SetShooterArticulator(float angle);
	virtual void Initialize() {};
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	float setpoint;
	static const float MAX_ERROR;
};

#endif
