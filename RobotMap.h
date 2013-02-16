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
const UINT8 DIGITAL_MODULE_PORT = 1,
	        SOLENOID_MODULE_PORT = 1;
/**@}*/



// TODO: Get real port numbers

/**
 * @defgroup pwmChannels PWM Channel Numbers
 * @{
 */
// PWM channels for the drivebase
const UINT32 LEFT_DRIVE_CHANNEL = 3,
	         RIGHT_DRIVE_CHANNEL = 4;
// PWM channels for the shooter
const UINT32 FIRST_SHOOTER_WHEEL_CHANNEL = 3,
	         SECOND_SHOOTER_WHEEL_CHANNEL = 6;
// PWM channels for the shooter articulator
const UINT32 ARTICULATOR_MOTOR_CHANNEL = 0;
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
const UINT32 FIRST_SHOOTER_ENCODER_CHANNEL_A = 4,
	         FIRST_SHOOTER_ENCODER_CHANNEL_B = 3,
             SECOND_SHOOTER_ENCODER_CHANNEL_A = 7,
	         SECOND_SHOOTER_ENCODER_CHANNEL_B = 8;
// Ditital I/O port for the shooter articulator
const UINT32 ARTICULATOR_POTENTIOMETER_CHANNEL = 0;
// Ditital I/O ports for the compressor
const UINT32 COMPRESSOR_PRESSURE_SWITCH_CHANNEL = 0,
		     COMPRESSOR_RELAY_CHANNEL = 0;
/**@}*/



/**
 * @defgroup solenoidChannels Solenoid Module Channel Numbers
 * @{
 */
// Solenoid ports for the shooter
const UINT32 EXTEND_DISK_PUSHER_CHANNEL = 8,
	         RETRACT_DISK_PUSHER_CHANNEL = 7;
/**@}*/

#endif // ROBOT_MAP_H
