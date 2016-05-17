#include <string>
#include "Player.h"

using namespace std;

Player::Player(string n, int s, int a, int w, int bA, int h)
{
	setName(n);
	setStrength(s);
	setAgility(a);
	setWisdom(w);
	setBaseAttack(bA);
	setHealth(h);
}