/**
 * @file CompressorSystem.h
 * @brief Declaration of the Compressor subsystem
 * @author Nyle Rodgers
 */
#ifndef COMPRESSORSYSTEM_H
#define COMPRESSORSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 * @brief The Compressor subsystem
 * 
 * Controls the compressor of the robot.
 */
class CompressorSystem: public Subsystem {
public:
	// Initilize the Compressor subsystem
	CompressorSystem();
private:
	Compressor *compressor;
};

#endif //COMPRESSORSYSTEM_H
