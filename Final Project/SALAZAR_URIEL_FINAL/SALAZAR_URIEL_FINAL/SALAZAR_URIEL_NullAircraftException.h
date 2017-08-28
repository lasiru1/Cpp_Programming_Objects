/***************************************************************************//**
* @file		SALAZAR_URIEL_NullAircraftException.h
* @brief	Final Project
* @author	Uriel Salazar
* @date		June 2016
* @details	
*******************************************************************************/

// prevent multiple inclusions
#ifndef NULLAIRCRAFTEXCEPTION_H
#define NULLAIRCRAFTEXCEPTION_H

// system libraries
#include <stdexcept>

// declare class "NullAircraftException"
class NullAircraftException : public std::runtime_error
{
public:
	NullAircraftException() : std::runtime_error(
		"No Aircraft Created") {}
};

#endif