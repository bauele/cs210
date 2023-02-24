#include "Menu.h"
#include "lib.h"
#include <iostream>
#include <iomanip>
#include <memory>

//	Construct a Menu object
//
//	@param t_menuTitle - Title of the menu to display
//	@param t_menuWidth - Amount of horizontal characters the menu will take up, > 0
Menu::Menu(string t_menuTitle, int t_menuWidth) {
	m_menuTitle = t_menuTitle;
	m_menuWidth = t_menuWidth;

	m_statusMessage = "";
	m_selectedField = 0;
	m_fields = vector<shared_ptr<Field>>();
}

//	Add a field to the Menu object
//
//	@param t_name				- Name of field to be shown to user
//	@param t_value				- Reference to initial value of field 
//	@param t_width				- Amount of horizontal characters available for the field, > 0
//	@optional param t_prefix	- String to be displayed immediately before t_value
void Menu::addField(string t_name, string& t_value, int t_width, string t_prefix) {
	shared_ptr<Field> field = make_shared<Field>(t_name, t_value, t_width, t_prefix);
	m_fields.push_back(field);
}

//	Display the menu
void Menu::printMenu() {
	//	Print out the top border
	cout << nCharString(m_menuWidth, '*') << endl;

	//	Print out the title of the menu
	cout << centeredString(m_menuWidth, m_menuTitle, '*') << endl;

	//	Print out all of the fields and associated values
	for (size_t i = 0; i < m_fields.size(); i++) {

		//	Get associated field data
		string fieldName = m_fields[i]->getName();
		string fieldValuePrefix = m_fields[i]->getValuePrefix();
		string fieldValue = m_fields[i]->getValue();

		//	If the current field is the one the user has selected, insert
		//	a special character to indicate that is their current field
		if (i == m_selectedField) {
			fieldValue.append(1, '_');
		}
		
		//	Determine how many characters of padding are needed to properly
		//	position the fieldValue. 2 must be subtracted in order to account
		//	for both the field selection character and for the 0-based index
		int requiredPaddingChars = m_menuWidth - fieldName.length() - 2;

		//	Output the fieldName and then right-align the fieldValue
		cout << fieldName << ": " << setw(requiredPaddingChars) << right << fieldValuePrefix + fieldValue << endl;
	}

	//	Display the menu's status message
	cout << m_statusMessage << endl;	
}

//	Handle input sent to the Menu object
//
//	@param c	- Character being sent by the user
//	@return		- True if user has selected to submit data, otherwise false
bool Menu::handleInput(char c) {
	
	//	Prevent any invalid characters from being passed in
	if (c > 0) {
		//	Up arrow key
		if (c == 72) {
			//	If user is not already in the first field, move cursor up and 
			//	remove message prompting user to continue to report
			if (!m_firstFieldSelected()) {
				m_moveCursorUpMenu();
				m_statusMessage = "";
			}
		}

		//	Down arrow key
		else if (c == 80) {
			//	If user is not already in the last field, move cursor down
			if (!m_lastFieldSelected()) {
				m_moveCursorDownMenu();
			}
			//	If user is already in the last field, hide the menu cursor
			//	and show message prompting user to continue to report
			else {
				m_hideMenuCursor();
				m_statusMessage = "Press enter to continue";
			}
		}

		//	Enter key
		else if (c == 13) {
			//	If user is not already in the last field, move cursor down
			if (!m_lastFieldSelected()) {
				m_moveCursorDownMenu();
			}

			//	If user is already in last field and the continue message is showing,
			//	hitting enter should submit the form by returning true
			else if (m_selectedField = m_fields.size() && m_statusMessage == "Press enter to continue") {
				m_hideMenuCursor();
				return true;
			}
			//	Otherwise, hide the menu cursor	and show message prompting user to continue to report
			else {
				m_hideMenuCursor();
				m_statusMessage = "Press enter to continue";
			}
		}

		//	Backspace key
		else if (c == 8) {
			//	Remove the last entered character from the selected field
			m_fields[m_selectedField]->removeLastChar();
		}

		//	Any digit key
		else if (isdigit(c)) {
			//	Add digit to selected field
			m_fields[m_selectedField]->appendChar(c);
		}

		//	Decimal point
		else if (c == '.') {
			//	If the field does not already contain a decimal point, add it to the
			//	selected field
			if (m_fields[m_selectedField]->getValue().find('.') == string::npos) {
				m_fields[m_selectedField]->appendChar(c);
			}
		}
	}

	//	Returning false indicates user is not done entering data
	return false;
}

//	Move cursor up the menu
void Menu::m_moveCursorUpMenu() {
	m_selectedField--;
}

//	Move cursor down the menu
void Menu::m_moveCursorDownMenu() {
	m_selectedField++;
}

//	Hide the cursor by setting it equal to the number
//	of menu fields
void Menu::m_hideMenuCursor() {
	m_selectedField = m_fields.size();
}

//	Determine if user is currently in the first field
//	@return	- True if user is in first field, otherwise false
bool Menu::m_firstFieldSelected() {
	if (m_selectedField == 0) {
		return true;
	}
	else {
		return false;
	}
}

//	Determine if user is currently in the last field
//	@return	- True if user is in last field, otherwise false
bool Menu::m_lastFieldSelected() {
	if (m_selectedField < m_fields.size()) {
		return false;
	}
	else {
		return true;
	}
}