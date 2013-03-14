#ifndef SHOOT_H
#define SHOOT_H

#include "../CommandBase.h"
#include "../CompilationSettings.h"

/**
 *
 *
 * @author Nyle
 */
class Shoot: public CommandBase {
public:
	Shoot();
	void Initialize() {}
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted() {}
};

#endif
