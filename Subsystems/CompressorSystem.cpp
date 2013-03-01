/**
 * @file CompressorSystem.cpp
 * @brief Implementation of the Compressor subsystem
 * @author Nyle Rodgers
 */
#include "CompressorSystem.h"
#include "../RobotMap.h"

CompressorSystem::CompressorSystem() : 
	Subsystem("CompressorSystem"),
	compressor( new Compressor( DIGITAL_MODULE_PORT,
			                    COMPRESSOR_PRESSURE_SWITCH_CHANNEL,
			                    DIGITAL_MODULE_PORT,
			                    COMPRESSOR_RELAY_CHANNEL ) ) {
	compressor->Start();
	
}
