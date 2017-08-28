/***************************************************************************//**
* @file		SALAZAR_URIEL_MenuException.h
* @brief	Final Project
* @author	Uriel Salazar
* @date		June 2016
* @details	
*******************************************************************************/

// prevent multiple inclusions
#ifndef MENUEXCEPTION_H
#define MENUEXCEPTION_H

// system libraries
#include <stdexcept>

// declare class "MenuException"
class MenuException : public std::runtime_error
{
public:
	MenuException() : std::runtime_error(
		"Invalid Action Code") {}
};

#endif