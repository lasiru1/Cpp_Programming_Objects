/***************************************************************************//**
* @file		SALAZAR_URIEL_Aircraft.h
* @brief	Final Project
* @author	Uriel Salazar
* @date		June 2016
* @details	
*******************************************************************************/

// prevent multiple inclusions
#ifndef AIRCRAFT_H
#define AIRCRAFT_H

// system libraries
#include <string>

// declare class "Aircraft"
class Aircraft
{
public:
	// constructor
	Aircraft(std::string, unsigned short, unsigned int, unsigned short,
			 unsigned int, float, unsigned short);

	// modelName; setter/getter
	void setModelName(std::string mn)
	{
		modelName = mn;
	}
	std::string getModelName()
	{
		return modelName;
	}

	// passengerCount; setter/getter
	void setPassengerCount(unsigned short pc)
	{
		passengerCount = pc;
	}
	unsigned short getPassengerCount()
	{
		return passengerCount;
	}

	// fuelCapacity; setter/getter
	void setFuelCapacity(unsigned int fc)
	{
		fuelCapacity = fc;
	}
	unsigned int getFuelCapacity()
	{
		return fuelCapacity;
	}

	// averageSpeed; setter/getter
	void setAverageSpeed(unsigned short as)
	{
		averageSpeed = as;
	}
	unsigned short getAverageSpeed()
	{
		return averageSpeed;
	}

	// averageAltitude; setter/getter
	void setAverageAltitude(unsigned int aa)
	{
		averageAltitude = aa;
	}
	unsigned int getAverageAltitude()
	{
		return averageAltitude;
	}

	// thrustWeightRatio; setter/getter
	void setThrustWeightRatio(float twr)
	{
		thrustWeightRatio = twr;
	}
	float getThrustWeightRatio()
	{
		return thrustWeightRatio;
	}

	// priorityLevel; setter/getter
	void setPriorityLevel(unsigned short pl)
	{
		priorityLevel = pl;
	}
	unsigned short getPriorityLevel()
	{
		return priorityLevel;
	}

	// virtual functions
	virtual void launch() {}
	virtual void land() {}

private:
	std::string		modelName;
	unsigned short	passengerCount;
	unsigned int	fuelCapacity;
	unsigned short	averageSpeed;
	unsigned int	averageAltitude;
	float			thrustWeightRatio;

public:
	unsigned short	priorityLevel;
};

#endif