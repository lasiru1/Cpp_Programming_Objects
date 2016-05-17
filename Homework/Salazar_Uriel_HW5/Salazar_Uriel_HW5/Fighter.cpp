#include "Fighter.h"
#include <string>

using namespace std;

Fighter::Fighter(string n, int s, int a, int w, int bA, int h, int oR) : Player(n, s, a, w, bA, h)
{
	setBrashStrike(oR);
}

int Fighter::attack()
{
	return getBaseAttack() + (getStrength() / 2) + brashStrike;
}