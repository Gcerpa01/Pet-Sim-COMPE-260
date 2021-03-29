// PetSim.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
/*
 **   Assignment:  PetSim Specification
 **
 **     Filename:PetSim.cpp
 **
 **       Author:  Gerardo Cerpa
 **        REDID:  819144749
 **
 **  Lab Section:  CompE260
 **     Due Date:  11/30/2020 @ 11:34PM
 **
 **  Description: Pet Simulator
 **
 **        Input:The user inputs a name that their pet will be referred to throughout the entirety of the game.
 *			  From then on, a menu is showing allowing the user to either play,feed,listen or exit the game.
 *			It then initiates the appropriate task for the thing the user asked.
 **
 **       Output: A menu displaying the different options for the player. Varying on their decision, the
			   player then sees the respective screen for the mode they have chosen. The player will also
			   be able to see their virtual pet doing the particular action they have chosen

 **      Caveats: There is no safe file for the player, meaning that if a player wants to continue using the same pet
 *			 theyd have to start again with the base conditions. In addition, with the fact that the pet is limited 
 *			as to how much it can play, it will also limit the player's experience.

 **      Version:  1.0
 **
		This program utilizes classes and instances in order to create a virtual pet. An object called game is created
		and is then run via the classes being defined in a header file and instantiated in a seperate .cpp file. Additionally, 
		an overloaded class constructor is used to allow the programmer to instantiate the class in one of two formats.
 */

#include "PetSimClass.h"

/*The checkString function only serves to check that the player has inputted 
alphanumeric characters for their virtual pet, returning there has been an error
otherwise*/

bool checkString(string input) {
	for (int i = 0; i < input.size(); i++) {
		if (isalpha(input[i]) == false) {
			cout << endl;
			cout << "Please use letters not numbers!!!" << endl;
			cout << endl;

			return false;
		}
	}
	return true;
}

int main()
{
	/*This section of the code is just a bonus I have added to allow the player to continue from a previous pet they had created
	in the past*/
	ifstream file("save.txt");
	if (file) {
		string name;
		int hungerLevel, boredomLevel;
		int user;
		cout << "Would you like to reload your last pet?" << endl;
		cout << "1. Yes   2. No" << endl;			
		cin >> user;
		 while (user < 1 || user > 2) {
			 cout << "Please select from the previous options" << endl;
			 cin.clear();
			 cin.ignore(10000, '\n');
			 cin >> user;
		}
		if (user == 1) {
			file >> name;
			file >> hungerLevel;
			file >> boredomLevel;

			PetSim digimon(name, hungerLevel, boredomLevel);
			digimon.Menu();
			return 0;
		}
	}

	string input;
	do {
		cout << "Welcome to PetSim!" << endl;
		cout << "You are about to get a VR Pet!" << endl;
		cout << "What would you like to name your pet?" << endl;
		cin >> input;

	} while (checkString(input) == false);

	PetSim digimon(input, 50, 50); //create a pet for the user with their selected name with base stats set to 50
	digimon.Menu();

}

