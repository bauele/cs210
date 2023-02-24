/*
 *	main.cpp
 * 
 *	This program will allow a user to enter initial
 *	investment information, then show reports with
 *	their projected yearly balances and earned 
 *	interest.
 *
 *  Date: 2-1-2023
 */

#include "Menu.h"

#include <conio.h>
#include <iostream>
#include <memory>
#include "Report.h"
#include "lib.h"
using namespace std;

int main() {
	//	Create variables to hold values the user will input into the menu form.
	//	These are provided default values at start. These variables will be 
	//	accessed by reference in the Menu object
	string initialAmount = "1.00";
	string monthlyDeposit = "50.00";
	string annualInterest = "5.00";
	string years = "5";

	const int MENU_WIDTH = 40;

	//	Create menu and add fields for user to interact with
	Menu menu(" Data Input ", MENU_WIDTH);
	menu.addField("Initial Investment Amount", initialAmount, 10, "$");
	menu.addField("Monthly Deposit", monthlyDeposit, 10, "$");
	menu.addField("Annual Interest", annualInterest, 5, "%");
	menu.addField("Number of Years", years, 2);
	menu.printMenu();

	//	Variables to hold user input and whether or not user is done with menu
	char input;
	bool finishedInput = false;
	
	do {
		//	Obtain pressed character without displaying it on screen
		input = _getch();

		//	Clear the screen
		system("CLS");

		//	Send user's input to the menu for processing
		finishedInput = menu.handleInput(input);

		//	Redraw the menu after input has been processed
		menu.printMenu();
	} while (!finishedInput);

	cout << endl << endl;

	// If any value has been deleted and not filled back in, change them to 0s
	setValueIfEmpty(initialAmount, "0");
	setValueIfEmpty(monthlyDeposit, "0");
	setValueIfEmpty(annualInterest, "0");
	setValueIfEmpty(years, "0");

	try {
		//	Generate the reports by converting the user input to floats
		const int REPORT_WIDTH = 74;

		Report noMonthly("Balance and Interest Without Additional Monthly Deposit", REPORT_WIDTH, stoi(years) * 12, stof(initialAmount), 0.00, stof(annualInterest));
		noMonthly.printReport();

		cout << endl;

		Report extraMonthly("Balance and Interest With Additional Monthly Deposits", REPORT_WIDTH, stoi(years) * 12, stof(initialAmount), stof(monthlyDeposit), stof(annualInterest));
		extraMonthly.printReport();
	}
	//	If any error occurs, inform the user they must try again
	catch (...) {
		cout << "You have entered invalid values. Please restart and try again.";
	}

	return 0;
}