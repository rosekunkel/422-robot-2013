/**
 * @file InterfaceMap.h
 * @brief A mapping for buttons on the joysticks
 *
 * Defines the button numbers used on the joysticks
 *
 * @author Nyle Rodgers
 */

#ifndef INTERFACE_MAP_H
#define INTERFACE_MAP_H

#include "WPILib.h"

/**
 * @defgroup leftPrimaryJoystick Button numbers for the left primary joystick
 * @{
 */
const UINT32 ONE_TENTH_SPEED_MULTIPLIER = 2,
             HALF_SPEED_MULTIPLIER = 1;
/**@}*/

/**
 * @defgroup rightPrimaryJoystick Button numbers for the right primary joystick
 * @{
 */
const UINT32 FULL_SPEED = 1;
/**@}*/

/**
 * @defgroup leftPrimaryJoystick Button numbers for the secondary joystick
 * @{
 */
// TODO: Rename setpoints to be more descriptive
const UINT32 AUTO_AIM = 1,
		     SETPOINT_ONE = 3,
		     SETPOINT_TWO = 4,
		     SETPOINT_THREE = 5;
/**@}*/

#endif // INTERFACE_MAP_H
