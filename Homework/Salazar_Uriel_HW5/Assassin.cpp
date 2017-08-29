#include "Assassin.h"
#include <string>

using namespace std;


Assassin::Assassin(std::string n, int s, int a, int w, int bA, int h, int sM) : Rogue(n, s, a, w, bA, h, sM)
{

}

int Assassin::backStab()
{
	return (getBaseAttack() + (getAgility() / 1.5) + 40);
}

int Assassin::attack()
{
	return (getBaseAttack() + (getAgility() / 1.5));
}