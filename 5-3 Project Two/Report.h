#pragma once
#ifndef REPORT_H
#define REPORT_H

#include <string>
#include <vector>
using namespace std;

class Report {
	public:
		Report(string, int, int, double, double, double);
		void printReport();

	private:
		vector<int> m_getColumnWidths();
		void m_printRow(vector<int> widths, vector<string> values);

		const vector<string> M_COLUMN_NAMES{ "Year", "Year End Balance", "Year End Earned Interest" };
		int m_reportWidth;
		string m_reportTitle;

		int m_months;
		double m_initialAmount;
		double m_monthlyAddition;
		double m_interestRate;
};

#endif

