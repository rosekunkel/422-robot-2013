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
	virtual void Initialize() {};
	virtual void Execute() ;
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted(){};
private:
	bool isFired;
};

#endif
