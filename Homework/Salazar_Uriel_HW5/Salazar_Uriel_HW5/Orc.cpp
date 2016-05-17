#include "Orc.h"
#include <string>

using namespace std;

Orc::Orc(string n, int s, int a, int w, int bA, int h, int oR) : Enemy(n, s, a, w, bA, h)
{
	setOrcRage(oR);
}

int Orc::attack()
{
	return getBaseAttack() + (getStrength() / 2) + orcRage;
}