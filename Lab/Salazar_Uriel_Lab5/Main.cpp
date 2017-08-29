/***************************************************************************//**
* @file		Main.cpp
* @brief	Lab#5 (Handed out)
* @author	Uriel Salazar
* @date		April 2016
* @details	Using derived classes to display information for house pets.
* @include	Main.cpp, HousePet.h, HousePet.cpp, PokemonHousePet.h,
			PokemonHousePet.cpp, DigimonHousePet.h, DigimonHousePet.cpp
*******************************************************************************/

// system libraries
#include <iostream>
using namespace std;

// user libraries
#include "PokemonHousePet.h"
#include "DigimonHousePet.h"

// begin execution
int main()
{
	// create object "myPokemon"
	PokemonHousePet myPokemon(
		"Charmander", "Pokemon", 0.6, 8.5, "Ember", "Pokeball", "Fire");

	DigimonHousePet myDigimon(
		"Agumon", "Digimon", 0.9, 20.0, "Pepper Breath", "Digivice", "Rookie");

	// display data members inside object "myHousePet"
	cout << "This is my 1st House Pet:\n\n";
	myPokemon.printPokemonHousePet();

	// display data members inside object "myHousePet"
	cout << "\n\nThis is my 2nd House Pet:\n\n";
	myDigimon.printDigimonHousePet();

	// wait for user input to exit the program
	cout << endl << endl;
	cin.get();

	// end execution
	return 0;
}