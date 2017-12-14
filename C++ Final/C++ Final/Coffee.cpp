#include "stdafx.h"
#include "Coffee.h"
#include <iostream>

using namespace std;


Coffee::Coffee()
{

}

bool Coffee::WaterAmountCheck(float a) //Function that has a float parameter called a that is used in the main to add to the current water amount
{
	if ( currentWater < waterNeeded) // if currentWater is less than the waterNeeded
	{

		return false;
		
	}
}

bool Coffee::WaterHeatAmount() // While the currentWaterTemp is less than 205 this bool function will return false. In the main when this is true it will end the while loop and the water will be "heated" to 205.
{
	while(currentWaterTemp < 205) // while this variable currentWaterTemp is less than 205
	{
		return false;
	}

}
void Coffee::WaterHeatIntro() //Prints the intro to heating the water 
{
	cout << endl;
	cout << "Current Water Temp is " << currentWaterTemp << endl; //writes current initial water temp
	cout << "Water Temp needs to be at 205 to make coffee" << endl; //tells you how hot the water needs to be
	cout << "Hit enter to heat up the water" << endl; //Lets you know that you need to hit enter to continue the program

	cin.get(); //Waits for Enter
	cin.get();
}


Coffee::~Coffee()
{
}
