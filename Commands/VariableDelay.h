#ifndef VARIABLE_DELAY_H
#define VARIABLE_DELAY_H

#include "../CompilationSettings.h"
#include "../CommandBase.h"

class VariableDelay : public CommandBase {
public:
	VariableDelay();
	void Initialize();
	void Execute() {}
	bool IsFinished();
	void End() {}
	void Interrupted() {}
private:
	static const float SCALING_FACTOR;
};

#endif // VARIABLE_DELAY_H
