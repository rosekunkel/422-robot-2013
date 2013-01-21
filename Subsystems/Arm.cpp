/**
 * @file Arm.cpp
 * @brief Implementation of the Arm subclass
 * @author Not Will Kunkel, Ryan Lucia, David Clayton, !Tom Burton
 */
 
 #include "../RobotMap.h"
 #include "Arm.h"
 
 /**
 * Initialize the climbing arms that climb (revolutionary concept)
 *
 * @author David Clayton, Ryan Lucia
 */
 Arm::Arm( UINT8 digitalModule, UINT32 armChannel, UINT32 winchChannel ) : 
		armMotor( new Talon( digitalModule, armChannel ) ),
		winchMotor( new Talon( digitalModule, winchChannel ) )
		
		// We don't need to use encoders to initialize this.
		// We do need talons.	

/** 
 * Drive each motor independently at a speed given in rotations/second.
 * 
 * @param[in] speed The speed the motor requires.
 *
 * @author Ryan Lucia
 */
 void Arm::turnMotor( float speed ) {
		armMotor->Set( speed );
}
/** 
 * Drive each motor independently at a speed given in rotations/second.
 * 
 * @param[in] speed The speed the winch requires.
 *
 * @author Ryan Lucia
 */
void Arm::runWinch( float speed ) {
		winchMotor->Set( speed )
}