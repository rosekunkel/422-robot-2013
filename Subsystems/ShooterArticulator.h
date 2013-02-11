/**
* @file Shooter.h
* @brief Decleration of the Shooter subsystem
* @author Nyle Rodgers
*/
#ifndef SHOOTERARTICULATOR_H
#define SHOOTERARTICULATOR_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 * @brief The shooter articulation subsystem
 * 
 * This subsystem controls the vertical aim of the shooter
 *
 * @author Nyle
 */
class ShooterArticulator: public Subsystem {
private:
	
public:
	ShooterArticulator();
	void InitDefaultCommand();
};

#endif //SHOOTERARTICULATOR_H
