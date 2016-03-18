// Lab1_MilitaryTime.cpp : Defines the entry point for the console application.
/*
a.Program Description
	This application asks the user for two times in military form and calculates the difference
	between the two times. This works whether the times are the same or following day.

b.Author
	EDGAR A. GALLO

c.Input variables
	firstTime, secondTime - These are then split into hours and minutes stored in 4 other varibles:
	firstHours, firstMinutes, secondHours, secondMinutes.

d.Process Flow
	The application asks users for 2 inputes of military time.
	It proceeds to subtract the first from the second time in case the times are within the same 2400 hour span.
	If the second time is less than the first time it is assumed that the hours will be in a future day and
		time is added accordingly to deal with the 'negative' values that would come about with the prior calculation.
	Once all calculations are taken care of, the user is shown the time difference split into hours and minutes.
	Finally the application asks the user if they would like to rerun or exit the application.

e.Output variables
	diffHours, diffMinutes.

*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//All variables initialized to 0 or blank. Names should be clear as to what they store.
	int firstTime, secondTime, firstHours, firstMinutes, secondHours, secondMinutes, diffHours, diffMinutes = 0;
	string reRun = "";

	cout << "Please enter the first time:" << endl; // Informs user to input first time.
	cin >> firstTime; // Takes input from user and stores it into first input time variable

	cout << "Please enter the second time:" << endl; // Informs user to input second time.
	cin >> secondTime; // Takes input from user and stores it into second input time variable

	// This is the method of splitting military time (ie 1230)
	// into individual hours and minutes (ie 12 hours and 30 minutes)
	firstHours = firstTime / 100;
	firstMinutes = firstTime % 100;

	secondHours = secondTime / 100;
	secondMinutes = secondTime % 100;

	// Takes the split times and computes the time difference.
	// Work is done if time 2 > time 1.
	diffHours = secondHours - firstHours;
	diffMinutes = secondMinutes - firstMinutes;

	// As stated, if the first time is greater (in the future) than the second time,
	// the calculations fall through this section.
#pragma region HandlingOfNextDayTime
	// This section checks for any values lower than 0, as in hours or minutes and
	// adjusts the values accordingly to adjust for 'future date' calculation
	if (diffHours < 0)
	{
		diffHours = diffHours + 24;
	}
	// If minutes need to be used, subtract 1 hour to keep time balanced.
	if (diffMinutes < 0)
	{
		diffMinutes = diffMinutes + 60;
		diffHours = diffHours--;
	}
#pragma endregion

	// Simply outputs the calculated difference of the two times.
	cout << "The difference in time is " << diffHours << " hours and " << diffMinutes << " minutes." << endl;

	// Asks user if they would like to run application again a Y[es] will restart the app,
	// anything else will return 0 and end.
	cout << endl << endl << "Would you like to calculate the value of different times? Y/N:" << endl;
	cin >> reRun;
	if (reRun == "y" || reRun == "Y" || reRun == "yes" || reRun == "YES")
	{
		system("cls"); // This command is MICROSOFT-Console specific to clear the console window for aesthetic reasons.
		main();
	}
	else
	{
		return 0;
	}
}

