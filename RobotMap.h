/**
 * @file RobotMap.h
 * @brief A mapping for ports on the robot
 *
 * Defines the port numbers for each module / digital sidecar port /
 * analog module port as constants.
 *
 * @author William Kunkel
 * @author Nyle Rodgers
 */

#ifndef ROBOT_MAP_H
#define ROBOT_MAP_H

#include "WPILib.h"

// Module numbers
static const UINT8 DIGITAL_MODULE_PORT_CHANNEL = 2,
	               SOLENOID_MODULE_PORT_CHANNEL = 3;

// TODO: Get real port numbers

// PWM channels for the drivebase
static const UINT32 LEFT_DRIVE_CHANNEL = 0,
	                RIGHT_DRIVE_CHANNEL = 0;

// PWM channels for the shooter
static const UINT32 SHOOTER_MOTOR_0_CHANNEL = 0,
	                SHOOTER_MOTOR_1_CHANNEL = 0;


// Digital I/O ports for the drivebase
static const UINT32 LEFT_ENCODER_CHANNEL_A = 0,
	                LEFT_ENCODER_CHANNEL_B = 0,
	                RIGHT_ENCODER_CHANNEL_A = 0,
	                RIGHT_ENCODER_CHANNEL_B = 0;
// Digital I/O ports for the shooter
static const UINT32 SHOOTER_ENCODER_A_CHANNEL = 0,
					SHOOTER_ENCODER_B_CHANNEL = 0;

// Relay ports for the shooter
static const UINT32 SHOOTER_PUSHER_SPIKE_CHANNEL = 0;

// Solenoid ports for the shooter
static const UINT32 SHOOTER_LOADER_SOLENOID_CHANNEL_EXTEND = 0,
	                SHOOTER_LOADER_SOLENOID_CHANNEL_RETRACT = 0;

#endif // ROBOT_MAP_H
