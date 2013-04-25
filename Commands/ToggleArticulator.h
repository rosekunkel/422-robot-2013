#ifndef TOGGLE_ARTICULATOR_H
#define TOGGLE_ARTICULATOR_H

#include "../CommandBase.h"
#include "../CompilationSettings.h"

#ifdef USE_PISTON_ARTICULATOR
#ifdef PRIMARY_CONTROLS_ARTICULATOR
class ToggleArticulator: public CommandBase {
public:
	ToggleArticulator();
	void Initialize();
	void Execute() {}
	bool IsFinished();
	void End() {}
	void Interrupted() {}
};
#endif
#endif
#endif // TOGGLE_ARTICULATOR_H
