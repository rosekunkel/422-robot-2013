#ifndef SET_SHOOTER_ARTICULATOR_H
#define SET_SHOOTER_ARTICULATOR_H

#include "../CompilationSettings.h"
#ifndef USE_PISTON_ARTICULATOR
#include "../CommandBase.h"

/**
 *
 *
 * @author Nyle
 */
class SetShooterArticulator: public CommandBase {
public:
	/// angle is in radians
	SetShooterArticulator(float displacement);
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
#endif
