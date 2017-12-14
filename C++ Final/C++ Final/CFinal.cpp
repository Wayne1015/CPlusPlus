
// CFinal.cpp : Defines the entry point for the console application.
//Must compile - Done
//Classes are seperated between header and cpp files; need multiple classes again - Done
//One Header per file - Done
// one cpp implementation per file - Done
//public methods must have descriptive comments that describe the API - Done


//Recipe for a cup of coffee
// 6 oz of water to make a cup
// Water has to be heated to 205 degrees
//Need 2 tablespoons of coffee grounds
//Must grind up ground before you can use them. 20 beans make up one tablespoon and you need 2 to make a cup



//Application Flow
//user must input the amount of cups of coffee they want to make. - Done
//The machine must check how much water is in the reservoir - Done
//If there isn't enough water the machine must fill itself - Done
//the machine heats the water in 15 degree intervals - Done
//The machine needs to retrieve the correct amounts of ground for the required cups - Done
//The grinder can only grind one bean at a time - Done
//Once the water is the right temp it is steeped through the beans - Done
//Once all cups have been made print, "You have made x cups of coffee - Done
//write any errors to the console window if any - Done
//
//
//Make a coffee machine class with water, beans, tblspoon. Bool
//
//
//

#include "stdafx.h"
#include "Coffee.h"
#include <iostream>
#include"CoffeeGrounds.h"

using namespace std;



int main()
{
	static float numberOfCupsWanted; //How many cups we want to make
	float currentCup; //What cup we are currently on
	
	//Intro
	cout << "How many cups of coffe should we  make?" << endl;
	cin >> numberOfCupsWanted; //Sets the user input to numberofCupsWanted
	//Intro End

	//Main game loop. While currentCup = 0 and its less than numberofCupWanted do this
	for (currentCup = 0; currentCup < numberOfCupsWanted; currentCup++)
	{
		//Stuff that needs to get reset every loop
		Coffee coffee;
		CoffeeGrounds coffeeGrounds;
		int cupsLeft = numberOfCupsWanted - currentCup; //To update the player on how many cups they still need to make
		//subtract the int numberofCupsWanted - int currentCup then store it in a new int called cupsLeft
		float beansAdded;
		
		static float waterAdded; //Value that user sets that is passed the WaterAmountCheck to add more water based on the float value

		int totalWaterNeeded = coffee.waterNeeded * cupsLeft; //Total amount of water needed to make the cups user wanted to make
		cout << endl;
		//Stuff that needs to get reset every loop End

		// Showing you how many cups you want, how many cups you've made, how much water you need in total for your next cups, telling you that the machine works with 6 at a time
		cout << "You want to make " << numberOfCupsWanted << " cups of coffee" << endl;
		cout << currentCup << " cups made so far" << endl;
		cout << "You need " << (totalWaterNeeded) << " cups of water to make " << cupsLeft << " cups of coffee" << endl;
		cout << "The Machine can hold 6 cups of water at a time" << endl;
		//End


		//Water Check//
		while (coffee.WaterAmountCheck(waterAdded) == false) //while currentWater is less than neededWater repeat this

		{
			cout << "Current count of water is: " << coffee.currentWater << endl;

			cout << "How much water should we add?" << endl;
			cin >> waterAdded; //Makes waterAdded = to the user input

			if (coffee.currentWater < coffee.waterNeeded) //If the currentWater is less than water needed add waterAdded to current water and write out how much was added
			{
				coffee.currentWater += waterAdded;
				cout << "Added " << waterAdded << " cups of water" << endl;



			}
			if (coffee.currentWater > coffee.waterNeeded)
			{
				//equation to set currentWater to 6 no matter what if it goes over
				int correctedWaterValue = coffee.currentWater - coffee.waterNeeded;
				cout << "Machine can only handle 6 cups.. pouring out excess" << endl;
				
				cout << "Current count of water is: " << coffee.currentWater - correctedWaterValue << endl; //If currentWater goes over 6 it will subtract whatever is over 6
				cout << "Water tank is full yo" << endl; //Lets you know the Water tank is full

			}
			if (coffee.currentWater == coffee.waterNeeded)
			{
				

				
				cout << "Water tank is full yo" << endl; //Lets you know the Water tank is full

			}


		}
		/*Water Check End*/
		
		
		//Heat up Water
		coffee.WaterHeatIntro(); //Prints the intro to heating the water
		
		while (coffee.WaterHeatAmount() == false) //While this bool is equal to false
		{

			coffee.currentWaterTemp += 15; //currentWaterTemp + 15
			
			cout << "Current Water Temp is " << coffee.currentWaterTemp << endl; //Print new water temp

			if (coffee.currentWaterTemp >= 205) //if currentWaterTemp is greater than or equal too 205
			{
				cout << "Water is heated" << endl; //Print the water is heated

			}

		}
		/*Heat up Water End*/
		/*Coffee Grounds Start*/
		
		
			cout << "Current amount of beans is " << coffeeGrounds.currentGrounds << endl;
			cout << "You need 20 beans to make a tablespoon, but the machine can handle one at a time" << endl;
			//cout << "How many beans should we grab?" << endl;
			while(coffeeGrounds.currentTblSpoons < coffeeGrounds.tblspoonsneeded)
			{
				
				cout << coffeeGrounds.currentTblSpoons << " tablespoons made so far" << endl;
				cin.get();
				for (int i = 0; i < coffeeGrounds.groundsneeded; i++)
				{
					cout << "Grounded a bean" << endl;
					cout << i + 1 << " beans grounded so far" << endl;
					
					

				}
				coffeeGrounds.currentTblSpoons += 1;
				
			
			}
			cout << coffeeGrounds.currentTblSpoons << " tablespoons made so far" << endl;
			cout << "Steeping grounds through hot water" << endl;
			cin.get();
			cout << "Pouring coffee into a cup" << endl;
		//End of the loop
		cout << "Cup of Coffee Made!" << endl;
	}
	//After all the cups of coffee are made
	
	cout << "You have made " << currentCup << " cups of coffee" << endl; //Print the currentCup which will be equal the numberofCupsWanted
	return 0;
}

