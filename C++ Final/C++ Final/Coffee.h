#pragma once
class Coffee
{

public:
	int currentWater = 0; // You start with zero water in the machine
	int *currentWaterPtr = &currentWater; // Creates a int pointer to the reference of the float currentWater

	int waterNeeded = 6; //Amount of water needed to make a cup of coffee

	float currentWaterTemp = 70.0f; // initial temperature of the water is set the 70 degrees
	float *CurrentWaterTempPtr = &currentWaterTemp; // float pointer to the value of the currentWaterTemp





	Coffee();
	bool WaterAmountCheck(float a); //Bool to check if the currentWater is less than waterNeeded
	bool WaterHeatAmount(); //Bool to heat up the water
	void WaterHeatIntro(); //Void that writes the WaterHeatIntro

	
	
	~Coffee();



};


