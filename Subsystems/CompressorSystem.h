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
 * @brief The compressor system
 * 
 * This system cotains the compressor
 *
 * @author Nyle
 */
class CompressorSystem: public Subsystem {
public:
	/// Constructor for the Compresor System
	CompressorSystem();
private:
	Compressor *compressor;
};

#endif//COMPRESSORSYSTEM_H
