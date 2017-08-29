#ifndef ROGUE_H
#define ROGUE_H

#include "Enemy.h"

class Rogue : public Enemy
{
public:
	Rogue(std::string, int, int, int, int, int, int);
	virtual int attack() override;
	virtual int backStab();
	void setSneakMod(int sM) { sneakMod = sM; }
	int getSneakMod() { return sneakMod; }
private:
	int sneakMod;
};

#endif