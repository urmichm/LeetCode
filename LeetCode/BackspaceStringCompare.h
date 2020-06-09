#pragma once
/**
 * Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.
 *
 * Example 1:
 * Input: S = "ab#c", T = "ad#c"
 * Output: true
 * Explanation: Both S and T become "ac".
 *
 * Example 2:
 * Input: S = "ab##", T = "c#d#"
 * Output: true
 * Explanation: Both S and T become "".
 *
 * Example 3:
 *  Input: S = "a##c", T = "#a#c"
 * Output: true
 * Explanation: Both S and T become "c".
 * 
 * Example 4:
 * Input: S = "a#c", T = "b"
 * Output: false
 * Explanation: S becomes "c" while T becomes "b".
 * Note:
 *       1 <= S.length <= 200
 *       1 <= T.length <= 200
 *       S and T only contain lowercase letters and '#' characters.
 * Follow up:
 *  Can you solve it in O(N) time and O(1) space?
 */

#include <iostream>
using namespace std;

bool backspaceCompare(string S, string T);
void backspaceCompare_run(void);


void backspaceCompare_run(void)
{
	cout << "test 1: " <<  backspaceCompare("###ab#c", "ad#c") << endl;
	cout << "test 2: " <<  backspaceCompare("a#b#", "a#d#") << endl;
	cout << "test 3: " <<  backspaceCompare("a##c", "#a#c") << endl;
	cout << "test 4: " << !backspaceCompare("a#c", "b") << endl;
	cout << "test 5: " <<  backspaceCompare("xywrrmp", "xywrrmu#p") << endl;
}


bool backspaceCompare(string S, string T) 
{
	// apply backspace
	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] == '#')
		{
			if (i == 0)
			{
				S.erase(0, 1);
			}
			else
			{
				S.erase(i - 1, i);
				i--;
			}
			i--;
		}
	}
	for (int i = 0; i < T.length(); i++)
	{
		if (T[i] == '#')
		{
			if (i == 0)
			{
				T.erase(0, 1);
			}
			else
			{
				T.erase(i - 1, i);
				i--;
			}
			i--;
		}
	}
	// compare length
	if (S.length() != T.length())
		return false;
	// compare strings 
	for (int i = 0; i < S.length(); i++)
		if (S[i] != T[i])
			return false;
	return true;
}