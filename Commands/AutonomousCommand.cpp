#include "AutonomousCommand.h"
#include "DriveRotations.h"
#include "VariableDelay.h"
#include "SetShooter.h"
#include "Shoot.h"

AutonomousCommand::AutonomousCommand() {
	AddSequential( new SetShooter( 35.0 ) );
	AddSequential( new VariableDelay() );
	for( int i = 0; i < 3; ++i ) {
		AddSequential( new Shoot() );
		AddSequential( new WaitCommand(3) );
	}
	AddSequential( new Shoot() );
}
