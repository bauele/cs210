#ifndef MENU_H
#define MENU_H

#include "Field.h"
#include <vector>
#include <memory>

using namespace std;

class Menu {
	public:
		Menu(string, int);

		void addField(string, string&, int, string = "");
		void printMenu();
		bool handleInput(char);
	private:
		void m_moveCursorUpMenu();
		void m_moveCursorDownMenu();
		void m_hideMenuCursor();
		bool m_firstFieldSelected();
		bool m_lastFieldSelected();

		int m_menuWidth;
		string m_menuTitle;
		string m_statusMessage;
		int m_selectedField;
		vector<shared_ptr<Field>> m_fields;

};

#endif

