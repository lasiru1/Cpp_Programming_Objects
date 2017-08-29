#include "Wizard.h"
#include <string>

using namespace std;

Wizard::Wizard(string n, int s, int a, int w, int bA, int h, int oR) : Player(n, s, a, w, bA, h)
{
	setArcLightning(oR);
}

int Wizard::flamingSphere()
{
	return (getBaseAttack() + (getWisdom() / 1.2) + 50);
}

int Wizard::attack()
{
	return getBaseAttack() + (getWisdom() / 2) + arcLightning;
}