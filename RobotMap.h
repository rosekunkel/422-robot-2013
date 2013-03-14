/**
 * @file RobotMap.h
 * @brief A mapping for ports on the robot
 *
 * Defines the port numbers for each module / digital sidecar port /
 * solenoid module port as global constants.
 *
 * @author William Kunkel
 * @author Nyle Rodgers
 */

#ifndef ROBOT_MAP_H
#define ROBOT_MAP_H

#include "WPILib.h"
#include "CompilationSettings.h"

/**
 * @defgroup modulePorts cRIO Module Port Numbers
 * @{
 */
const UINT8 ANALOG_MODULE_PORT = 1,
	        DIGITAL_MODULE_PORT = 1,
	        SOLENOID_MODULE_PORT = 1;
/**@}*/




/**
 * @defgroup pwmChannels PWM Channel Numbers
 * @{
 */
// PWM channels for the drivebase
const UINT32 LEFT_DRIVE_CHANNEL = 1,
	         RIGHT_DRIVE_CHANNEL = 2;
// PWM channels for the shooter
const UINT32 FIRST_SHOOTER_WHEEL_CHANNEL = 4,
	         SECOND_SHOOTER_WHEEL_CHANNEL = 5;
// PWM channels for the shooter articulator
const UINT32 ARTICULATOR_MOTOR_CHANNEL = 3;
/**@}*/


/**
 * @defgroup ioChannels Digital I/O Channel Numbers
 * @{
 */
// Digital I/O ports for the drivebase
const UINT32 LEFT_DRIVE_ENCODER_CHANNEL_A = 1,
	         LEFT_DRIVE_ENCODER_CHANNEL_B = 2,
	         RIGHT_DRIVE_ENCODER_CHANNEL_A = 5,
	         RIGHT_DRIVE_ENCODER_CHANNEL_B = 6;
// Digital I/O ports for the shooter
const UINT32 FIRST_SHOOTER_ENCODER_CHANNEL_A = 14,
	         FIRST_SHOOTER_ENCODER_CHANNEL_B = 13,
             SECOND_SHOOTER_ENCODER_CHANNEL_A = 10,
	         SECOND_SHOOTER_ENCODER_CHANNEL_B = 9;
// Ditital I/O port for the shooter articulator
const UINT32 ARTICULATOR_ENCODER_CHANNEL_A = 3,
		     ARTICULATOR_ENCODER_CHANNEL_B = 4,
             ARTICULATOR_TOP_LIMIT_SWITCH_CHANNEL = 12,
		     ARTICULATOR_BOTTOM_LIMIT_SWITCH_CHANNEL = 11;
// Ditital I/O ports for the compressor
const UINT32 COMPRESSOR_PRESSURE_SWITCH_CHANNEL = 8,
		     COMPRESSOR_RELAY_CHANNEL = 1;
/**@}*/



/**
 * @defgroup solenoidChannels Solenoid Module Channel Numbers
 * @{
 */
// Solenoid ports for the shooter
const UINT32 EXTEND_DISK_PUSHER_CHANNEL = 8,
	         RETRACT_DISK_PUSHER_CHANNEL = 7;
// Solenoid ports for the climber
const UINT32 CLIMBER_RIGHT_SERVO_CHANNEL = 10,
		     CLIMBER_LEFT_SERVO_CHANNEL = 9;
/**@}*/

/**
 * @defgroup LED Channel Numbers
 * @{
 */
// Red Relay Ports
const UINT32 RED_RELAY_CHANNEL = 3;
// Blue Relay Ports
const UINT32 BLUE_RELAY_CHANNEL = 4;
// Green Relay Ports
const UINT32 GREEN_RELAY_CHANNEL = 5;
/**@}*/

/**
 * @defgroup Analog Channel Numbers
 * @{
 */
const UINT32 LEFT_ANTENNA_CHANNEL = 8,
	         RIGHT_ANTENNA_CHANNEL = 7,
	         VARIABLE_DIAL_CHANNEL = 1;

/**
 * @defgroup PS3 Controller Mappings
 * @{
 */
#ifdef USE_PS3_CONTROLLER
const UINT32 PS3_LEFT_X = 1,
	         PS3_LEFT_Y = 2,
	         PS3_RIGHT_X = 4,
	         PS3_RIGHT_Y = 3;

const int PS3_SELECT   =  1,
	      PS3_L3       =  2,
	      PS3_R3       =  3,
	      PS3_START    =  4,
	      PS3_UP       =  5,
	      PS3_RIGHT    =  6,
	      PS3_DOWN     =  7,
	      PS3_LEFT     =  8,
	      PS3_R1       =  9,
	      PS3_R2       = 10,
	      PS3_L1       = 11,
	      PS3_L2       = 12,
	      PS3_TRIANGLE = 13,
	      PS3_CIRCLE   = 14,
	      PS3_X        = 15,
	      PS3_SQUARE   = 16,
	      PS3_HOME     = 17;
#endif
/**@}*/

/**
 * @defgroup GameCube Controller Mappings
 * @{
 */
#ifdef USE_GAMECUBE_CONTROLLER
const UINT32 GC_LEFT_X = 1,
	         GC_LEFT_Y = 2,
	         GC_C_STICK_X = 3,
	         GC_C_STICK_Y = 4;

const int GC_A     =  1,
	      GC_B     =  2,
	      GC_X     =  3,
	      GC_Y     =  4,
	      GC_L     =  5,
	      GC_R     =  6,
	      GC_Z     =  7,
	      GC_START =  8,
	      GC_LEFT  =  9,
	      GC_RIGHT = 10,
	      GC_DOWN  = 11,
	      GC_UP    = 12;
#endif
/**@}*/

#endif // ROBOT_MAP_H
