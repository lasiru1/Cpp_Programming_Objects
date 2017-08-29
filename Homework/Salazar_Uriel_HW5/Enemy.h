#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy
{
public:
	Enemy(std::string, int, int, int, int, int);
	void setName(std::string n) { name = n; }
	std::string getName() { return name; }
	void setStrength(int str) { strength = str; }
	int getStrength() { return strength; }
	void setAgility(int agi) { agility = agi; }
	int getAgility() { return agility; }
	void setWisdom(int wis) { wisdom = wis; }
	int getWisdom() { return wisdom; }
	void setBaseAttack(int bAtk) { baseAttack = bAtk; }
	int getBaseAttack() { return baseAttack; }
	void setHealth(int h) { health = h; }
	int getHealth() { return health; }

	virtual int attack() = 0;
	virtual int backStab() { return 0; }
private:
	std::string name;
	int strength;
	int agility;
	int wisdom;
	int baseAttack;
	int health;
};

#endif