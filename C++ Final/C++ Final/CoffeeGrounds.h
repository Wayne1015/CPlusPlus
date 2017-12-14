#pragma once
class CoffeeGrounds
{
public:
	CoffeeGrounds();

	int currentGrounds = 0;//Variable to store current Grounds
	int *currentGroundsPtr = &currentGrounds; // Ptr to value for current grounds
	int currentTblSpoons = 0;//Variable for current tablespoons
	int *currentTblSpoonsPtr = &currentTblSpoons;//ptr for current tablespoons
	int tblspoonsneeded = 2;//Amount of tablespoons needed to make a cup
	int groundsneeded = 20; //Amount of grounds needed to make a cup

	




	~CoffeeGrounds();
};

