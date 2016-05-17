#ifndef WARLOCK_H
#define WARLOCK_H

#include "Enemy.h"

class Warlock : public Enemy
{
public:
	Warlock(std::string, int, int, int, int, int, int);
	virtual int attack() override;
	void castSpell();
	void setSpellSlots(int sS) { spellSlots = sS; }
	int getSpellSlots() { return spellSlots; }
private:
	int spellSlots;
	void decrementSpellSlots();
};

#endif