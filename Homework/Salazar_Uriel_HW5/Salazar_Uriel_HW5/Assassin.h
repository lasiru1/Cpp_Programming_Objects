#ifndef ASSASSIN_H
#define ASSASSIN_H

// specialized rogue

#include "Rogue.h"

class Assassin : public Rogue
{
public:
	Assassin::Assassin(std::string, int, int, int, int, int, int);
	virtual int backStab() override;
	virtual int attack() override;
};

#endif