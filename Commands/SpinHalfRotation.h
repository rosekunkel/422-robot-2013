#ifndef SPINHALFROTATION_H
#define SPINHALFROTATION_H

#include "../CommandBase.h"
#include "../CompilationSettings.h"

/**
 *
 *
 * @author Nyle
 */
class SpinHalfRotation: public CommandBase {
public:
	SpinHalfRotation( bool isLeft );
	virtual void Initialize();
	virtual void Execute() {};
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	bool isLeft;
};

#endif
