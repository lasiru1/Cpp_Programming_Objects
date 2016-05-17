#include "Ranger.h"
#include <string>

using namespace std;

Ranger::Ranger(string n, int s, int a, int w, int bA, int h, int oR) : Player(n, s, a, w, bA, h)
{
	setWarningShot(oR);
}

int Ranger::attack()
{
	return getBaseAttack() + (getAgility() / 2) + warningShot;
}