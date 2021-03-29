#include "PetSimClass.h"

/*The PetMood function calculates the moodlevel of the pet by getting the sum of
boht the hunger levels and boredom levels.*/
int PetSim::PetMood() {
	int moodLevel;
	moodLevel = GetHunger() + GetBoredom();
	return moodLevel;
}

/*The Talk function takes into account the pet's mood to have the pet state how it
is feeling with the player. In addition, each mood range has a set animation/image
to display its mood to the user*/
void PetSim::Talk() {
	cout << endl;
	cout << "-------------------------------------" << endl;
	cout << "               TALKING               " << endl;
	cout << "-------------------------------------" << endl;
	int mood;
	mood = PetMood();
	if (mood < 7) {
		TopBorder();
		cout << "|            ^_________^            |" << endl;
		cout << "|           ( = ^ w ^ = )b          |" << endl;
		BotBorder();
		cout << name << ": Im feeling amazing today~!" << endl;
	}

	else if (mood >= 7) {
		if (mood >= 16 && mood <= 21) {
			TopBorder();
			cout << "|            ^_________^            |" << endl;
			cout << "|        O  (  = __ =  ) O          |" << endl;
			BotBorder();
			cout << name << ": Hmph!! I'm frustrated and annoyed! Hmph!" << endl;
		}
		if (mood > 21) {
			TopBorder();
			cout << "|            ^_________^            |" << endl;
			cout << "|           q( > __ <  '+)          |" << endl;
			BotBorder();
			cout << name << ": PAY ATTENTION TO ME!!" << endl;
			cout << name << ": MAKE ME FEEL BETTER!!!" << endl;
		}
		else {
			TopBorder();
			cout << "|           ^  _O ___^   _O         |" << endl;
			cout << "|           ( / . 3 .  )/           |" << endl;
			BotBorder();

			cout << name << ": Im alright." << endl;
		}
	}
	PassTime(gameTime);
	Sleep(2500);
	DisplayPetBehavior();
}

/*This setHunger and GetHunger functions set the values for the new hunger values and obtain them
via the use of a this pointer to prevent other classes from accessing the private variables*/
void PetSim::SetHunger(int change) {
	this->hungerLevel -= change;
	if (hungerLevel > 100) {
		this->hungerLevel = 100;
	}
	else if (hungerLevel < 0) {
		this->hungerLevel = 0;
	}
}

int PetSim::GetHunger() {
	return hungerLevel;
}

/*This setBored and GetBoredom functions set the values for the new hunger values and obtain them
via the use of a this pointer to prevent other classes from accessing the private variables*/
void PetSim::SetBoredom(int change) {
	this->boredomLevel -= change;
	if (boredomLevel > 100) {
		this->boredomLevel = 100;
	}
	else if (boredomLevel < 0) {
		this->boredomLevel = 0;
	}
}

int PetSim::GetBoredom() {
	return boredomLevel;
}

string PetSim::GetName() {
	return name;
}
/*The feedPet function first checks to see how many times it has been called. If it has been
called 4 times, it no longer allows the user to call it. In addition each feeding lowers the
amount of hunger the pet has*/
void PetSim::FeedPet() {
	cout << endl;
	cout << "-------------------------------------" << endl;
	cout << "               FEEDING               " << endl;
	cout << "-------------------------------------" << endl;
	int bonus, change;
	if (food < 4) {
		TopBorder();
		cout << "|          ^_________^              |" << endl;
		cout << "|          (\\_O...O_/)              |" << endl;
		BotBorder();
		cout << endl;
		cout << "You have provided " << name << " with one meal" << endl;
		std::srand(unsigned(time(0)));
		bonus = 1 + (rand() % ((food + 1) * 5)); // this bonus provides a "luck" like roll to fill up the pet more depending on how much its filled
		change = (int)(5 * bonus) / (1 + (rand() % 3)); //the change variable provides a further roll providing a max of -100 hunger points
		SetHunger(change); //call SetHunger to lower the HungerLevel by the amount of change
	}
	else if (food >= 4) {
		cout << endl;

		cout << "WARNING!!: " << name << "can no longer be fed!!!" << endl;
	}
	food += 1;
	PassTime(gameTime);
	Sleep(2000);
	DisplayPetBehavior();
}

/*This function just serves as a display function of a dance to be called
when the player plays with their pet*/
void PetSim::DisplayDance() {
	cout << "-------------------------------------" << endl;
	cout << "          DANCE TIME!!!              " << endl;
	cout << "-------------------------------------" << endl;

	TopBorder();
	cout << "|           ^_________^             |" << endl;
	cout << "|       o--(  ^  w   ^ )--o         |" << endl;
	BotBorder();
	
	Sleep(500); //the sleep function is used to delay the next images in order to create a mini animation and help
			  //the player understand what is happening
	
	TopBorder();
	cout << "|      O                            |" << endl;
	cout << "|       \\  ^_________^              |" << endl;
	cout << "|         (  ^  w   ^ ) \\           |" << endl;
	cout << "|                         O         |" << endl;
	BotBorder();
	
	Sleep(500);
	
	TopBorder();
	cout << "|           ^_________^  O          |" << endl;
	cout << "|         /(  ^  w   ^ )/           |" << endl;
	cout << "|        O                          |" << endl;
	BotBorder();
	
	Sleep(500);

	TopBorder();
	cout << "|           ^_________^             |" << endl;
	cout << "|       o--(  ^  w   ^ )--o         |" << endl;
	BotBorder();
}

/*The play function is called when the player selects to play with their pet. The function
makes sure it has not been called 4 times. If it has, it then informs the player they can no longer
play with their pet. In addition, it lowers the boredom level of the pet each time it is used.*/
void PetSim::Play() {
	cout << endl;
	cout << "-------------------------------------" << endl;
	cout << "             PLAYING                 " << endl;
	cout << "-------------------------------------" << endl;
	int bonus, change;
	if (fun < 4) {
		DisplayDance();
		cout << name << ": That was fun~!" << endl;
		cout << name << ": Let's do that again sometime!" << endl;
		std::srand(unsigned(time(0)));
		bonus = 1 + (rand() % ((fun + 1) * 5)); // this bonus provides a "luck" like roll to lower the boredom levels more, the more times the pet is played with
		change = (int)(5 * bonus) / (1 + (rand() % 3)); //the change variable provides a further roll providing a max of -100 boredom points
		SetBoredom(change); //call SetBoredom to lower the BoredomLevel by the amount of change
	}
	else if (fun >= 4) {
		cout << endl;

		cout << "WARNING!!:" << name << " can no longer play" << endl;
	}
	fun += 1;
	PassTime(gameTime);
	Sleep(2000);
	DisplayPetBehavior();
}

/*The passtime behavior calls sethunger and setboredom to add 1 point of hunger and boredom
each time an action is done with a pet to simulate the passage of time*/
void PetSim::PassTime(int time) {
	SetHunger(-time);
	SetBoredom(-time);
}



/*This function displays how the pet looks like depending on their boredom and hunger
levels to display their mood once called in the DisplayPetBehavior function*/
void PetSim::Animation() {
	TopBorder();
	if ((GetHunger() >= 3 && GetHunger() <= 11) || (GetBoredom() >= 3 && GetBoredom() <= 11)) {
		cout << "|            ^_________^            |" << endl;
		cout << "|            (  . ~ .  )            |" << endl;
	}
	else if ((GetHunger() > 11) || (GetBoredom() > 11)) {

		cout << "|           ^________^  O           |" << endl;
		cout << "|           (+ > __ < )/            |" << endl;
	}
	else if ((GetHunger() < 3) && (GetBoredom() < 3)) {

		cout << "|           ^_________^             |" << endl;
		cout << "|           (  . w .  )             |" << endl;
	}
	BotBorder();
}

/*This function checks the boredomlevel and hunger level of the player's pet. It then
displays an appropriate message to inform the player how the pet is doing in terms of its
stats by displaying the levels to the player through the get functions*/
void PetSim::DisplayPetBehavior() {
	cout << "-------------------------------------" << endl;
	cout << "              STATUS                 " << endl;
	cout << "-------------------------------------" << endl;
	Animation();
	if (GetHunger() < 3) {
		cout << name << ": I'm good on food!" << endl;
	}
	else if (GetHunger() >= 3 && GetHunger() <= 11) {
		cout << name << ": Erggg..." << endl;
		cout << name << ": I'm hungry....." << endl;

	}
	else if (GetHunger() > 11) {
		cout << name << ": IM STARVING!!!" << endl;
		cout << name << ": PLEASE... YOU GOT TO FEED ME SOMETHING" << endl;
	}

	if (GetBoredom() < 3) {
		cout << name << ":I'm good on playing!" << endl;
	}
	else if (GetBoredom() >= 3 && GetBoredom() <= 11) {
		cout << name << ": Eh.." << endl;
		cout << name << ": I'm kind of bored..." << endl;
	}
	else if (GetBoredom() > 11) {
		cout << name << ": UGH!" << endl;
		cout << name << ": LET'S DO SOMETHING ALREADY!!!!" << endl;
		cout << name << ": PLEASE...IM SOOO BORED!!!" << endl;
	}

	cout << "Hunger: " << hungerLevel << endl;
	cout << "Boredom: " << boredomLevel << endl;
	Sleep(250);
}

/*The menu is continually asks the player for an input on what action they would like to
do with their pet. The game then calls the appropriate function to do that task and will only
let the player exit the game when they choose the exit option*/
void PetSim::Menu() {
	int user = 0;
	do {
		cout << "-------------------------------------" << endl;
		cout << "                MENU                 " << endl;
		cout << "-------------------------------------" << endl;
		cout << endl;
		cout << "     1.Play            2.Listen" << endl;
		cout << "     3.Feed            4.Exit" << endl;
		cin >> user;
		switch (user) {
		case 1:
			Play();
			break;
		case 2:
			Talk();
			break;
		case 3:
			FeedPet();
			break;
		case 4:
			Save();
			cout << endl;
			cout << name << ": BYE!!" << endl;
			cout << "-------------------------------------" << endl;
			cout << "-------------  EXITING    -----------" << endl;
			cout << "-------------------------------------" << endl;
			break;
		default:
			cout << "!!!INVALID CHOICE!!!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
	} while (user != 4);
}

void PetSim::TopBorder() {
	cout << endl;
	cout << "-------------------------------------" << endl;
	cout << "|                                   |" << endl;
	cout << "|                                   |" << endl;
	
}
void PetSim::BotBorder() {
	cout << "|                                   |" << endl;
	cout << "|                                   |" << endl;
	cout << "-------------------------------------" << endl;
	cout << endl;
}

/*This function allows the player to save their pet for future use if they would like*/
void PetSim::Save() {
	int opt;
	cout << "-------------------------------------" << endl;
	cout << "                Save?                 " << endl;
	cout << "-------------------------------------" << endl;
	cout << "Would you like to save your pet for later?" << endl;
	cout << "     1.Yes            2.No" << endl;
	cin >> opt;
	while (opt < 1 || opt > 2) {
		cout << "!!!INVALID CHOICE!!!" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> opt;
	}
	if (opt == 1) {
		ofstream file("save.txt");
		file << GetName() << " ";
		file << GetHunger()<< " ";
		file << GetBoredom()<< " ";
		cout << "-------------------------------------" << endl;
		cout << "               Saving                " << endl;
		cout << "-------------------------------------" << endl;
	}

	


}