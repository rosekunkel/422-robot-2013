#ifndef TOGGLECLIMBER_H
#define TOGGLECLIMBER_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Nyle
 */
class ToggleClimber: public CommandBase {
public:
	ToggleClimber();
	virtual void Initialize();
	virtual void Execute() {};
	virtual bool IsFinished();
	virtual void End() {};
	virtual void Interrupted() {};
};

#endif
