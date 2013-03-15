#ifndef NUKE_H
#define NUKE_H

#include "../CompilationSettings.h"
#include "../CommandBase.h"

class Nuke: public CommandBase {
public:
	Nuke();
	void Initialize() {}
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted() {}
};

#endif // NUKE_H
