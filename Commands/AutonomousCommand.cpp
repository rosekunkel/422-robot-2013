#include "AutonomousCommand.h"
#include "DriveRotations.h"
#include "VariableDelay.h"
#include "SetShooter.h"
#include "Shoot.h"
#include "ControlLights.h"

AutonomousCommand::AutonomousCommand() {
	ControlLights::Color allianceColor = ControlLights::GREEN;
	DriverStation::Alliance currentAlliance = DriverStation::GetInstance()->GetAlliance();
	if( currentAlliance == DriverStation::kRed ) {
		allianceColor = ControlLights::RED;
	}
	else if( currentAlliance == DriverStation::kBlue ) {
			allianceColor = ControlLights::BLUE;
	}
	AddParallel( new ControlLights(allianceColor) );
	AddSequential( new SetShooter( 35.0 ) );
	AddSequential( new VariableDelay() );
	for( int i = 0; i < 3; ++i ) {
		AddSequential( new Shoot() );
		AddSequential( new WaitCommand(3) );
	}
	AddSequential( new Shoot() );
}
