#ifndef SHOW_ALIGNED_H
#define SHOW_ALIGNED_H

#include "../CompilationSettings.h"
#include "../CommandBase.h"

class ShowAligned : public CommandBase {
public:
	ShowAligned();
	void Initialize() {}
	void Execute();
	bool IsFinished();
	void End() {}
	void Interrupted() {}
};

#endif // SHOW_ALIGNED_H
