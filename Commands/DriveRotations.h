#ifndef DRIVE_ROTATIONS_H
#define DRIVE_ROTATIONS_H
#include "WPILib.h"
#include "../CompilationSettings.h"
#include "../CommandBase.h"

class DriveRotations : public CommandBase {
public:
	DriveRotations( double rotations );
	void Initialize();
	void Execute() {}
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double rotationsToDrive;
};
#endif // DRVIE_ROTATIONS_H
