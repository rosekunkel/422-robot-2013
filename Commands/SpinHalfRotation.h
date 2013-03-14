#ifndef SPIN_HALF_ROTATION_H
#define SPIN_HALF_ROTATION_H

#include "../CommandBase.h"
#include "../CompilationSettings.h"

/**
 *
 *
 * @author Nyle
 */
class SpinHalfRotation: public CommandBase {
public:
	SpinHalfRotation();
	void Initialize();
	void Execute() {}
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
