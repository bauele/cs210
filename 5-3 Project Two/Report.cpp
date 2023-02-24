#include "Report.h"
#include "lib.h"
#include <iostream>
#include <iomanip>
#include <sstream>

//	Construct a Report object
//
//	@param t_reportTitle - Title of the report to display
//	@param t_reportWidth - Amount of horizontal characters the menu will take up, > 0
Report::Report(string t_reportTitle, int t_reportWidth, int t_months, double t_initialAmount, double t_monthlyAddition, double t_interestRate) {
	m_reportTitle = t_reportTitle;
	m_reportWidth = t_reportWidth;

	m_months = t_months;
	m_initialAmount = t_initialAmount;
	m_monthlyAddition = t_monthlyAddition;
	m_interestRate = t_interestRate;
}

//	Print the interest report
void Report::printReport() {
	//	Print the report title
	cout << centeredString(m_reportWidth, m_reportTitle, ' ') << endl;

	//	Print the top border
	cout << nCharString(m_reportWidth, '=') << endl;

	//	Calculate required widths of the columns. These widths will also be used
	//	when printing out a row so that the values will be aligned in the same
	//	positions as the column names are
	vector<int> widths = m_getColumnWidths();

	//	Print out the column names
	m_printRow(widths, M_COLUMN_NAMES);

	//	Print out the border underneath the column names
	cout << nCharString(m_reportWidth, '-') << endl;

	double initial = m_initialAmount;
	double yearlyInterest = 0.00;

	for (int i = 0; i < m_months; i++) {

		yearlyInterest += calculateMonthlyInterest(initial, m_interestRate, m_monthlyAddition);
		initial += calculateMonthlyInterest(initial, m_interestRate, m_monthlyAddition) + m_monthlyAddition;

		//	If i is an interval of a year, print out the data
		if ( (i + 1) % 12 == 0) {
			//	Unfortunately, I'm passing in a vector of strings so that I can easily determine the width of the columns
			//	in the report. In order for me to format all deciamls to two places, I'll have to use a stringstream in
			//	order to take advanatage of the setprecision() function
			stringstream monthlyInterestStream, initialStream;
			monthlyInterestStream << fixed << setprecision(2) << yearlyInterest;
			initialStream << fixed << setprecision(2) << initial;

			//	Reminder that 1 has to be added to i to offset the 0-based index
			vector<string> values = { to_string((i + 1) / 12),	"$" + initialStream.str(), "$" + monthlyInterestStream.str()};
			m_printRow(widths, values);

			// Reset yearly interest every year
			yearlyInterest = 0.00;
		}
	}
}

//	Obtain a vector containing the required width of each column
//	@return		- A vector containing the width required for each column to
//				be able to display its name and have proper spacing in relation
//				to the other columns
vector<int> Report::m_getColumnWidths() {
	//	Determine how many characters are needed to hold all the column names
	int columnChars = 0;
	for (int i = 0; i < M_COLUMN_NAMES.size(); i++) {
		string columnString = M_COLUMN_NAMES.at(i);

		//	Increment columnChars by the amount of characters of current column
		//	plus an extra character for spacing
		columnChars += columnString.length() + 1;
	}

	//	Determine how many characters are left over after accounting for all
	//	the column names. This will be the amount of padding to be distributed
	//	throughout each row
	int charsRemaining = m_reportWidth - columnChars;

	//	Determine how many characters should be in between each column
	int charsBetween = charsRemaining / M_COLUMN_NAMES.size() - 1;

	//	Deterine how many characters are "leftover" if the division did not
	//	work out to perfect integer number
	int charsLeftover = charsRemaining % M_COLUMN_NAMES.size();

	//	Vector to be returned containing the required widths of all the columns
	vector<int> columnWidths;

	//	For each column name, calculate the amount of space needed to show its
	//	name and evenly distribute the remaining space
	for (int i = 0; i < M_COLUMN_NAMES.size(); i++) {
		//	If it is the first column, add any leftover chars here
		if (i == 0) {
			columnWidths.push_back(M_COLUMN_NAMES[i].length() + charsBetween + charsLeftover);
		}

		else {
			columnWidths.push_back(M_COLUMN_NAMES[i].length() + charsBetween);
		}
	}

	return columnWidths;
}

//	Print a row of the report
//	@param widths	- A vector containing the sizing information for each column in the row
//	@param	values	- A vector containing the actual values to be printed out
void Report::m_printRow(vector<int> widths, vector<string> values) {
	for (int i = 0; i < widths.size(); i++) {
		cout << " " << rightString(widths[i], values[i], ' ') << " ";
	}

	cout << endl;
}
