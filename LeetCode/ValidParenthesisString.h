#pragma once
/**
 * Valid Parenthesis String
 * Given a string containing only three types of characters: '(', ')' and '*', 
 * write a function to check whether this string is valid. 
 * We define the validity of a string by these rules:
 *
 * Any left parenthesis '(' must have a corresponding right parenthesis ')'.
 * Any right parenthesis ')' must have a corresponding left parenthesis '('.
 * Left parenthesis '(' must go before the corresponding right parenthesis ')'.
 * '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
 * 
 * An empty string is also valid.
 * Example 1:
 * Input: "()"		
 * Output: True
 * Example 2:
 * Input: "(*)"		
 * Output: True
 * Example 3:
 * Input: "(*))"	
 * Output: True
 *
 * Note:	The string size will be in the range [1, 100].
 */

#include<string>
#include<algorithm>
#include<iostream>
using namespace std;


bool checkValidString(string s)
{
	const int n = s.length();
	if (0 == n) return true;

	int dp[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dp[i][j] = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == '*') dp[i][i] = true;
		if (i < n - 1)
			if (s[i] == '(' || s[i] == '*')
				if (s[i + 1] == ')' || s[i + 1] == '*')
					dp[i][i + 1] = true;
	}

	for (int size = 2; size < n; size++) {
		for (int i = 0; i + size < n; i++) {
			if (s[i] == '*' && dp[i + 1][i + size]) {
				dp[i][i + size] = true;
			}
			else if (s[i] == '(' || s[i] == '*') {
				for (int k = i + 1; k <= i + size; k++) {
					if ((s[k] == ')' || s[k] == '*')
						&& ((k == (i + 1)) || (true == dp[i + 1][k - 1]))
						&& (k == (i + size) || true == dp[k + 1][i + size]))
					{
						dp[i][i + size] = true;
					}
				}
			}
		}
	}

	return dp[0][n - 1];
}


void checkValidString_run(void)
{
	cout << checkValidString("()") << endl;
	cout << checkValidString("(*)") << endl;
	cout << checkValidString("(*))") << endl;
}