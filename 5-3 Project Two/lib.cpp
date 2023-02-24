#include "lib.h"

//	Returns a string of length n, each character a c.
//	For example, nCharString(5, '*') should return "*****"
//
//	@param n	- Length of string, >= 0
//	@return		String of n c's
string nCharString(size_t n, char c) {
	string str = string(n, c);

	return str;
}

//	Returns a string of length n, with string s in the center surrounded by c
//	@param n	- String length, >= 0
//	@param s	- Substring to be centered
//	@param c	- Character to surround both sides of s
//	@return		A string of length n where s is equally surrounded by c on both sides
string centeredString(size_t n, string s, char c) {
	int requiredPaddingChars = n - s.length();

	size_t leftPadding = requiredPaddingChars / 2;
	size_t rightPadding = requiredPaddingChars - leftPadding;

	return nCharString(leftPadding, c) + s + nCharString(rightPadding, c);
}

//	Returns a string of length n, with string s is right-aligned padded by c
//	@param n	- String length, >= 0
//	@param s	- Substring to be right-aligned
//	@param c	- Character to surround left side of s
//	@return		A string of length n where s is right-aligned
string rightString(size_t n, string s, char c) {
	int requiredPaddingChars = n - s.length();

	size_t leftPadding = requiredPaddingChars;

	return nCharString(leftPadding, c) + s;
}

//	Sets s to newValue if it is an empty string
//	@param	s			- String to check if is empty
//	@param	newValue	- Value to set s to if s is an empty string
void setValueIfEmpty(string& s, string newValue) {
	if (s == "") {
		s = newValue;
	}
}

//	Calculate the interest gained in a monthly period
//	@param initial			- Balance at start of month, > 0
//	@param rate				- Interest rate, > 0
//	@optional param deposit	- Amount of additional money to add during month
//	@return					Amount of interest gained in the month
double calculateMonthlyInterest(double initial, double rate, double deposit) {
	return (initial + deposit) * ((rate / 100) / 12.0);
}