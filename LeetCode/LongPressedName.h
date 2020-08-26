#pragma once
/**
 * Your friend is typing his name into a keyboard.  
 * Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.
 *
 * You examine the typed characters of the keyboard.  
 * Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.
 *
 * Constraints:
 * 1 <= name.length <= 1000
 * 1 <= typed.length <= 1000
 * The characters of name and typed are lowercase letters.
 *
 */


#include <string>
#include <iostream>
using namespace std;

void isLongPressedName(void);
bool isLongPressedName(string name, string typed);

bool isLongPressedName(string name, string typed)
{
	char prev = 0;
	unsigned int n = 0;
	unsigned int t = 0;
	bool result = true;

	while (result && t < typed.length() && n < name.length())
	{
		if (prev == 0)
		{
			if (name[n] == typed[t])
			{
				prev = name[n];
				n++; t++;
			}
			else
			{
				result = false;
			}
		}
		else
		{
			if (name[n] == typed[t])
			{
				prev = name[n];
				n++; t++;
			}
			else if (typed[t] == prev)
			{
				t++;
			}
			else
			{
				result = false;
			}
		}
	}
	// finish typed
	while (result && t < typed.length())
	{
		if (typed[t++] != prev)
			result = false;
	}

	
	return (result && n == name.length() && t == typed.length());
}


void isLongPressedName(void)
{
	{
		string  name = "alex", typed = "aaleex";
		bool Output = true;
		bool actual = isLongPressedName(name, typed);
		cout << (Output == actual ? "OK" : "KO") << endl;
	}
	{
		string name = "saeed", typed = "ssaaedd";
		bool Output = false;
		bool actual = isLongPressedName(name, typed);
		cout << (Output == actual ? "OK" : "KO") << endl;
	}
	{
		string name = "leelee", typed = "lleeelee";
		bool Output = true;
		bool actual = isLongPressedName(name, typed);
		cout << (Output == actual ? "OK" : "KO") << endl;
	}
	{
		string  name = "laiden", typed = "laiden";
		bool Output = true;
		bool actual = isLongPressedName(name, typed);
		cout << (Output == actual ? "OK" : "KO") << endl;
	}
}
