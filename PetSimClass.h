#pragma once
#ifndef _PET_SIM_CLASS
#define _PET_SIM_CLASS

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <ctype.h>
#include <Windows.h> //used for Sleep() for animations

using namespace std;

class PetSim {
private:
	int hungerLevel;
	int boredomLevel;
	int gameTime = 1;
	string name;
	int PetMood();
	void PassTime(int = 1);
	int food = 0;
	int fun = 0;
public:
	void Talk();
	void FeedPet();
	void Play();
	void DisplayPetBehavior();
	void Menu();
	void Save();
	PetSim() {}

	PetSim(string _name, int _hungerLevel, int _boredomLevel) {
		this->name = _name;
		this->hungerLevel = _hungerLevel;
		this->boredomLevel = _boredomLevel;
		DisplayPetBehavior();
	}
	void DisplayDance();
	void SetHunger(int change);
	int GetHunger();
	void SetBoredom(int change);
	int GetBoredom();
	string GetName();
	void Animation();
	void TopBorder();
	void BotBorder();
};
#endif
