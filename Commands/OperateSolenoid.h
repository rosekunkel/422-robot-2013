#ifndef OPERATESOLENOID_H
#define OPERATESOLENOID_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Nyle
 */
class OperateSolenoid: public CommandBase {
public:
	OperateSolenoid();
	virtual void Initialize() {};
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End() {};
	virtual void Interrupted() {};
private:
	bool isExtended;
};

#endif
