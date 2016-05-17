/***************************************************************************//**
* @file     Main.cpp
* @brief    HW#5 (Enemy Polymorphism Modification)
* @author   Uriel Salazar
* @date     May 2016
* @details  Create a container of pointers of a base class and control each
			party with polymorphism
*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "Enemy.h"
#include "Player.h"
#include "Rogue.h"
#include "Orc.h"
#include "Warlock.h"
#include "Assassin.h"
#include "Fighter.h"
#include "Ranger.h"
#include "Wizard.h"

using namespace std;

void displayEnemyMenu();
void displayPlayerMenu();

int main()
{
	// declare variables
	int userChoice;
	bool keepGoing = true;
	int enemyPartyCount = 0;
	int playerPartyCount = 0;
	int enemyDamage = 0;
	int playerDamage = 0;
	vector <Enemy*> enemies;
	vector <Player*> players;

	// create enemy party
	do
	{
		displayEnemyMenu();
		cin >> userChoice;
		cout << endl;

		if (userChoice == 1)
		{
			enemies.push_back(new Orc("Orkul", 6, 2, 1, 5, 20, 1));
		}
		else if (userChoice == 2)
		{
			enemies.push_back(new Warlock("Locky", 1, 2, 10, 5, 3, 5));
		}
		else if (userChoice == 3)
		{
			enemies.push_back(new Rogue("Rouge", 3, 8, 2, 6, 6, 2));
		}
		else if (userChoice == 4)
		{
			enemies.push_back(new Assassin("Stabby", 5, 24, 6, 20, 10, 1));
		}
		else if (userChoice == 5)
		{
			keepGoing = false;
		}

		// increment enemy party
		if (userChoice != 5)
		{
			enemyPartyCount++;
		}

	} while (keepGoing);

	// reset "keepGoing" bool
	keepGoing = true;

	// create player party
	do
	{
		displayPlayerMenu();
		cin >> userChoice;
		cout << endl;

		if (userChoice == 1)
		{
			players.push_back(new Fighter("Ryu", 5, 3, 3, 6, 4, 5));
		}
		else if (userChoice == 2)
		{
			players.push_back(new Ranger("Chuck", 1, 10, 7, 5, 3, 4));
		}
		else if (userChoice == 3)
		{
			players.push_back(new Wizard("Gandalf", 3, 6, 22, 7, 6, 2));
		}
		else if (userChoice == 4)
		{
			keepGoing = false;
		}
		
		// increment player party
		if (userChoice != 4)
		{
			playerPartyCount++;
		}

	} while (keepGoing);

	cout << "*************************" << endl;
	cout << "         FIGHT!!!        " << endl;
	cout << "*************************" << endl;
	cout << endl;

	for (auto range : enemies)
	{
		cout << range->getName() << " attacks! ";
		cout << "Damage: " << range->attack() << endl;

		// calculate total damage
		enemyDamage += range->attack();
	}

	cout << endl;
	cout << "Assassin's are awesome, so they get an extra attack! ";
	cout << "Backstab Damage: " << enemies[3]->backStab() << endl;
	enemyDamage += enemies[3]->backStab();

	cout << endl;
	for (auto range : players)
	{
		cout << range->getName() << " attacks! ";
		cout << "Damage: " << range->attack() << endl;

		// calculate total damage
		playerDamage += range->attack();
	}

	cout << endl;
	cout << "Wizard's are awesome, so they get an extra attack! ";
	cout << "Flaming Sphere Damage: " << players[2]->flamingSphere() << endl;
	playerDamage += players[2]->flamingSphere();

	cout << endl << endl;
	if (enemyDamage > playerDamage)
	{
		cout << "The enemy party dealt a total of " << enemyDamage << "!\n";
		cout << "Player party is dead, the enemy party wins!" << endl;
	}
	else if(enemyDamage < playerDamage)
	{
		cout << "The player party dealt a total of " << playerDamage << "!\n";
		cout << "Enemy party is dead, the player party wins!" << endl;
	}
	else if (enemyDamage == playerDamage)
	{
		cout << "Both parties dealt the same amount of damage! (" << playerDamage << ")\n";
		cout << "Both parties are dead! Nobody wins!" << endl;
	}
	cout << endl << endl;

	return 0;
}

void displayEnemyMenu()
{
	cout << "*************************" << endl;
	cout << "       ENEMY PARTY       " << endl;
	cout << "*************************" << endl;
	cout << "1. Create Orc" << endl;
	cout << "2. Create Warlock" << endl;
	cout << "3. Create Rogue" << endl;
	cout << "4. Create Assassin" << endl;
	cout << "5. Done Creating Enemy Party" << endl;
	cout << endl;
	cout << "Enter Choice: ";
}

void displayPlayerMenu()
{
	cout << "*************************" << endl;
	cout << "       PLAYER PARTY      " << endl;
	cout << "*************************" << endl;
	cout << "1. Create Fighter" << endl;
	cout << "2. Create Ranger" << endl;
	cout << "3. Create Wizard" << endl;
	cout << "4. Done Creating Player Party" << endl;
	cout << endl;
	cout << "Enter Choice: ";
}