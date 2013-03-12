#ifndef RAISECLIMBER_H
#define RAISECLIMBER_H

#include "../CommandBase.h"
#include "../CompilationSettings.h"

/**
 *
 *
 * @author Nyle
 */
class RaiseClimber: public CommandBase {
public:
	RaiseClimber();
	virtual void Initialize();
	virtual void Execute() {};
	virtual bool IsFinished();
	virtual void End() {};
	virtual void Interrupted() {};
};

#endif
