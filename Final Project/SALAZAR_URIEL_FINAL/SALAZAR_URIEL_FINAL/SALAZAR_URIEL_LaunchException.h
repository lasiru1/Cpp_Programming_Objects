/***************************************************************************//**
* @file		SALAZAR_URIEL_LaunchException.h
* @brief	Final Project
* @author	Uriel Salazar
* @date		June 2016
* @details	
*******************************************************************************/

// prevent multiple inclusions
#ifndef LAUNCHEXCEPTION_H
#define LAUNCHEXCEPTION_H

// system libraries
#include <stdexcept>

// declare class "LaunchException"
class LaunchException : public std::runtime_error
{
public:
	LaunchException() : std::runtime_error(
		"Minimum of 3 Aircraft required to launch") {}
};

#endif