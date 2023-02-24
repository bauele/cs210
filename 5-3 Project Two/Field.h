#ifndef FIELD_H
#define FIELD_H

#include <string>
#include <memory>
using namespace std;

class Field {
	public:
		//	Construct a Field object
		//
		//	@param t_name				- Name of field to be shown to user
		//	@param t_value				- Reference to initial value of field 
		//	@param t_width				- Amount of horizontal characters available for the field, > 0
		//	@optional param t_prefix	- String to be displayed immediately before t_value
		//
		//	Note: This code is required to be in the .h file due to reference variables requiring instant initialization
		Field(string t_name, string& t_value, int t_width, string t_prefix = "") :
			m_fieldName(t_name), m_fieldValue(t_value), m_fieldValueWidth(t_width), m_fieldValuePrefix(t_prefix) { }

		string getName()		{ return m_fieldName; }
		string getValue()		{ return m_fieldValue; }
		string getValuePrefix() { return m_fieldValuePrefix;  }

		void removeLastChar();
		void appendChar(char);

	private:
		string m_fieldName;
		string& m_fieldValue;
		int m_fieldValueWidth;

		string m_fieldValuePrefix;
};

#endif

