#ifndef CONTROLLIGHTS_H
#define CONTROLLIGHTS_H

#include "../CommandBase.h"
#include "../CompilationSettings.h"

/**
 *
 *
 * @author Lucario
 */
class ControlLights: public CommandBase {
public:
	ControlLights(int whichLight);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End() {};
	virtual void Interrupted() {};
private:
	int light;
};

#endif
