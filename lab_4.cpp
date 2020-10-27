#include <iostream>
using namespace std;

class Casino{
protected:
	int victoryMoney;
	int quantityOfPlayers;

public:
	Casino(int victoryMoney = 0, int quantityOfPlayers = 1){
		//cout << "Constructor Casino" << endl;
		this->victoryMoney = victoryMoney;
		this->quantityOfPlayers = quantityOfPlayers;
	}
	~Casino(){
		//cout << "Destructor Casino" << endl;
	}
	void Show();
};

void Casino::Show(){
	cout << "Amount of players - " << quantityOfPlayers << ", won money - " << victoryMoney << "$." << endl;
}

class Poker : public Casino{
	int quantityOfCards;
	int bet;

public:
	Poker(int quantityOfCards = 54, int bet = 0, int victoryMoney = 0, int quantityOfPlayers = 2) : Casino (victoryMoney, quantityOfPlayers){
		//cout << "Constructor Poker" << endl;
		this->quantityOfCards = quantityOfCards;
		this->bet = bet;
	}
	~Poker(){
		//cout << "Destructor Poker" << endl;
	}
	void Show();
};

void Poker::Show(){
	cout << "Amount of players in Poker - " << quantityOfPlayers << ", won money - " << victoryMoney << "$, used quantity of cards - " <<
			quantityOfCards << ", bet of player - " << bet << "." << endl;
}

class Slots : public Casino{
	int amountOfRollers;
	bool isWinCombination;
	int paidMoney;

public:
	Slots(int amountOfRollers = 3, bool isWinCombination = false, int paidMoney = 0, int victoryMoney = 0, int quantityOfPlayers = 1) : Casino(victoryMoney, quantityOfPlayers){
		//cout << "Constructor Slots" << endl;
		this->amountOfRollers = amountOfRollers;
		this->isWinCombination = isWinCombination;
		this->paidMoney = paidMoney;
	}
	~Slots(){
		//cout << "Destructor Slots" << endl;
	}
	void Show();
};

void Slots::Show(){
	string combination = "no";

	if(isWinCombination){
		combination = "yes";
	}
	cout << "Amount of players in Slots - " << quantityOfPlayers << ", won money - " << victoryMoney << "$, used quantity of rollers - " <<
			amountOfRollers << ", paid money by player - " << paidMoney << ", is it currently a win combination - " << combination << "." << endl;
}

class Dice : public Casino{
	int quantityOfDices;
	int score;

public:
	Dice(int quantityOfDices = 2, int score = 0, int victoryMoney = 0, int quantityOfPlayers = 2) : Casino(victoryMoney, quantityOfPlayers){
		//cout << "Constructor Dice" << endl;
		this->quantityOfDices = quantityOfDices;
		this->score = score;
	}
	~Dice(){
		//cout << "Destructor Dice" << endl;
	}
	void Show();
};

void Dice::Show(){
	cout << "Amount of players in Dice - " << quantityOfPlayers << ", won money - " << victoryMoney << "$, used amount of dices - " <<
			quantityOfDices << ", score - " << score << "." << endl;
}

bool IsNumber(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int main(){
	//CASINO
	cout << "CASINO OBJECT";
	Casino casino_byDefault;
	cout << "\nBase class (by default): ";
	casino_byDefault.Show();

	Casino casinoObject = Casino(100, 4);
	cout << "Base class (changed settings): ";
	casinoObject.Show();

	string players, money;
	Casino casino_byUser;
	cout << "\nEnter the correct data, otherwise will be created default object: " << endl;
	cout << "Amount of players = ";
	cin >> players;
	cout << "Amount of won money = ";
	cin >> money;

	if(IsNumber(players) && IsNumber(money)){
		casino_byUser = Casino(stoi(money), stoi(players));
		cout << "\nObject Casino was successfully created!" << endl;
	} else {
		cout << "\nError (object by default)" << endl;
	}
	casino_byUser.Show();

	//POKER
	cout << "\nPOKER OBJECT";
	Poker poker_byDefault;
	cout << "\nBase class (by default): ";
	poker_byDefault.Show();

	string cards, bet;
	Poker poker_byUser;
	cout << "\nEnter the correct data, otherwise will be created default object: " << endl;
	cout << "Amount of players = ";
	cin >> players;
	cout << "Amount of cards = ";
	cin >> cards;
	cout << "Bet money = ";
	cin >> bet;
	cout << "Amount of won money = ";
	cin >> money;

	if(IsNumber(cards) && IsNumber(bet) && IsNumber(players) && IsNumber(money)){
		poker_byUser = Poker(stoi(cards), stoi(bet), stoi(money), stoi(players));
		cout << "\nObject Poker was successfully created!" << endl;
	} else {
		cout << "\nError (object by default)" << endl;
	}
	poker_byUser.Show();

	//SLOTS
	cout << "\nSLOTS OBJECT";
	Slots slots_byDefault;
	cout << "\nBase class (by default) ";
	slots_byDefault.Show();

	string rollers, paid;
	char win;
	Slots slots_byUser;
	cout << "\nEnter the correct data, otherwise will be created default object: " << endl;
	cout << "Amount of players = ";
	cin >> players;
	cout << "Amount of rollers = ";
	cin >> rollers;
	cout << "Paid money = ";
	cin >> paid;
	cout << "Amount of won money = ";
	cin >> money;
	cout << "Is it a win combinaton (y/n) = ";
	cin >> win;

	if(IsNumber(rollers) && IsNumber(paid) && IsNumber(players) && IsNumber(money)){
		if(win == 'y' || win == 'Y'/*stricmp(win, 'y')*/){
			slots_byUser = Slots(stoi(rollers), true, stoi(paid), stoi(money), stoi(players));
			cout << "\nObject Slots was successfully created!" << endl;
		} else if (win == 'n' || win == 'N'/*stricmp(win, 'n')*/){
			slots_byUser = Slots(stoi(rollers), false, stoi(paid), stoi(money), stoi(players));
			cout << "\nObject Slots was successfully created!" << endl;
		} else{
			cout << "\nError (object by default)" << endl;
		}
	} else {
		cout << "\nError (object by default)" << endl;
	}
	slots_byUser.Show();

	//Dices
	cout << "\nDICE OBJECT";
	Dice dice_byDefault;
	cout << "\nBase class (by default) ";
	dice_byDefault.Show();

	string dice, score;
	Dice dice_byUser;
	cout << "\nEnter the correct data, otherwise will be created default object: " << endl;
	cout << "Amount of players = ";
	cin >> players;
	cout << "Amount of dices = ";
	cin >> dice;
	cout << "Score = ";
	cin >> score;
	cout << "Amount of won money = ";
	cin >> money;

	if(IsNumber(dice) && IsNumber(score) && IsNumber(players) && IsNumber(money)){
		dice_byUser = Dice(stoi(dice), stoi(score), stoi(money), stoi(players));
		cout << "\nObject Dice was successfully created!" << endl;
	} else {
		cout << "\nError (object by default)" << endl;
	}
	dice_byUser.Show();
	return 0;
}
