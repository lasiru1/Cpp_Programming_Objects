#include <string>
#include "Enemy.h"

using namespace std;

Enemy::Enemy(string n, int s, int a, int w, int bA, int h)
{
	setName(n);
	setStrength(s);
	setAgility(a);
	setWisdom(w);
	setBaseAttack(bA);
	setHealth(h);
}