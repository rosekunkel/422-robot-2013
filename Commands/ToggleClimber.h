#ifndef TOGGLE_CLIMBER_H
#define TOGGLE_CLIMBER_H

#include "../CommandBase.h"
#include "../CompilationSettings.h"

class ToggleClimber: public CommandBase {
public:
	ToggleClimber();
	void Initialize();
	void Execute() {}
	bool IsFinished();
	void End() {}
	void Interrupted() {}
};

#endif
