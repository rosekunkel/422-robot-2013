#ifndef TOGGLE_FLASHLIGHT_H
#define TOGGLE_FLASHLIGHT_H

#include "../CommandBase.h"
#include "../CompilationSettings.h"

class ToggleFlashlight: public CommandBase {
public:
	ToggleFlashlight();
	void Initialize();
	void Execute() {}
	bool IsFinished();
	void End() {}
	void Interrupted() {}
};

#endif // TOGGLE_FLASHLIGHT_H
