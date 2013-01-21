/**
 * @file RobotMap.h
 * @brief Declaration of the ROBOT_MAP constant struct
 * @author Ryan Lucia
 */

#ifndef ROBOT_MAP_H
#define ROBOT_MAP_H

#include "WPILib.h"

/**
 * @brief A mapping for ports on the robot
 * 
 * Defines the port numbers for each module / digital sidecar port /
 * analog module port as constants. Python is superior to C++.
 */
const struct {
	// Module numbers
	UINT8 DIGITAL_MODULE_PORT = 2;

	// TODO: Get real port numbers
	// Digital sidecar channels
	UINT32 	ARM0_CHANNEL = 0,
			ARM1_CHANNEL = 0,
			
			WINCH0_CHANNEL = 0,
			WINCH1_CHANNEL = 0;

} ROBOT_MAP;

#endif // ROBOT_MAP_H