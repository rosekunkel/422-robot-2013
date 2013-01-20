/**
 * @file RobotMap.h
 * @brief A mapping for ports on the robot
 *
 * Defines the port numbers for each module / digital sidecar port /
 * analog module port as constants.
 *
 * @author William Kunkel
 */

#ifndef ROBOT_MAP_H
#define ROBOT_MAP_H

#include "WPILib.h"

// Module numbers
UINT8 DIGITAL_MODULE_PORT = 2;

// TODO: Get real port numbers
// Digital sidecar channels
UINT32 LEFT_DRIVE_CHANNEL = 0,
	   RIGHT_DRIVE_CHANNEL = 0,

	   LEFT_ENCODER_CHANNEL_A = 0,
	   LEFT_ENCODER_CHANNEL_B = 0,

	   RIGHT_ENCODER_CHANNEL_A = 0,
	   RIGHT_ENCODER_CHANNEL_B = 0;

#endif // ROBOT_MAP_H
