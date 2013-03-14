#include "AutonomousCommand.h"
#include "VariableDelay.h"
#include "Shoot.h"

AutonomousCommand::AutonomousCommand() {
	AddSequential( new VariableDelay() );
	for( int i = 0; i < 4; ++i ) {
		AddSequential( new Shoot() );
		AddSequential( new WaitCommand(0.5) );
	}
}
