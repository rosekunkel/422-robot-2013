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

/**
 * @defgroup modulePorts cRIO Module Port Numbers
 * @{
 */
static const UINT8 DIGITAL_MODULE_PORT_CHANNEL = 2,
	               SOLENOID_MODULE_PORT_CHANNEL = 3;
/**@}*/



// TODO: Get real port numbers

/**
 * @defgroup pwmChannels PWM Channel Numbers
 * @{
 */
// PWM channels for the drivebase
static const UINT32 LEFT_DRIVE_CHANNEL = 0,
	                RIGHT_DRIVE_CHANNEL = 0;
// PWM channels for the shooter
static const UINT32 INITIAL_SHOOTER_WHEEL_CHANNEL = 0,
	                SECOND_SHOOTER_WHEEL_CHANNEL = 0;
/**@}*/


/**
 * @defgroup ioChannels Digital I/O Channel Numbers
 * @{
 */
// Digital I/O ports for the drivebase
static const UINT32 LEFT_DRIVE_ENCODER_CHANNEL_A = 0,
	                LEFT_DRIVE_ENCODER_CHANNEL_B = 0,
	                RIGHT_DRIVE_ENCODER_CHANNEL_A = 0,
	                RIGHT_DRIVE_ENCODER_CHANNEL_B = 0;
// Digital I/O ports for the shooter
static const UINT32 SHOOTER_ENCODER_CHANNEL_A = 0,
					SHOOTER_ENCODER_CHANNEL_B = 0;
/**@}*/



/**
 * @defgroup relayChannels Relay Channel Numbers
 * @{
 */
// Relay ports for the shooter
static const UINT32 HOPPER_WHEEL_CHANNEL = 0;
/**@}*/



/**
 * @defgroup solenoidChannels Solenoid Module Channel Numbers
 * @{
 */
// Solenoid ports for the shooter
static const UINT32 EXTEND_DSIK_PUSHER_CHANNEL = 0,
	                RETRACT_DISK_PUSHER_CHANNEL = 0;
/**@}*/

#endif // ROBOT_MAP_H
