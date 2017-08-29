#include "Warlock.h"
#include <string>

using namespace std;

Warlock::Warlock(string n, int s, int a, int w, int bA, int h, int sS) : Enemy(n, s, a, w, bA, h)
{
	setSpellSlots(sS);
}

int Warlock::attack()
{
	return getBaseAttack() + (getWisdom() / 2);
}

void Warlock::decrementSpellSlots()
{
	//this exists
}