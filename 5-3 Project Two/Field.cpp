#include "Field.h"

//	Append a character to the field's value
//	@param c - Character to append to the field's value
void Field::appendChar(char c) {
	//	Only append the character if the field is not
	//	already above it's width capacity
	if (getValue().length() < m_fieldValueWidth) {
		m_fieldValue.append(1, c);
	}
}

//	Remove a character from the field's value
void Field::removeLastChar() {
	//	Only attempt to remove the character if there is at least
	//	one character in the field
	if (getValue().size() != 0) {
		m_fieldValue.pop_back();
	}
}