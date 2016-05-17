#include "Rogue.h"
#include <string>

using namespace std;

Rogue::Rogue(string n, int s, int a, int w, int bA, int h, int sM) : Enemy(n, s, a, w, bA, h)
{
	setSneakMod(sM);
}

int Rogue::backStab()
{
	//this exists
	return 0;
}

int Rogue::attack()
{
	return getBaseAttack() + (getAgility() / 2);
}