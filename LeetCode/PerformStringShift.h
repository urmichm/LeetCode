#pragma once
/**
 * Perform String Shifts
 * You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:
 * 
 * direction can be 0 (for left shift) or 1 (for right shift).
 * amount is the amount by which string s is to be shifted.
 * A left shift by 1 means remove the first character of s and append it to the end.
 * Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
 * Return the final string after all operations.
 *
 * Example 1:
 * Input: s = "abc", shift = [[0,1],[1,2]]
 * Output: "cab"
 * Explanation:
 * [0,1] means shift to left by 1. "abc" -> "bca"
 * [1,2] means shift to right by 2. "bca" -> "cab"
 *
 * Example 2:
 * Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
 * Output: "efgabcd"
 * Explanation:
 * [1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
 * [1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
 * [0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
 * [1,3] means shift to right by 3. "abcdefg" -> "efgabcd"
 * 
 * Constraints:
 * 1 <= s.length <= 100
 * s only contains lower case English letters.
 * 1 <= shift.length <= 100
 * shift[i].length == 2
 * 0 <= shift[i][0] <= 1
 * 0 <= shift[i][1] <= 100
 */


#include <vector>
#include <algorithm>
using namespace std;

string stringShift(string s, vector<vector<int>>& shift)
{
	// 0 - left  shift 
	// 1 - right shift
	int amount = 0;
	const unsigned int len = s.length();
	// calculate shift
	for (auto s : shift)
	{
		if (s[0] == 1)
			amount = amount + s[1];
		else
			amount = amount - s[1];
	}
	// apply shift if needed
	if (amount != 0)
	{
		if (amount > 0)
		{
			amount = abs(amount) % len;
			// right shift (remove the last character of s and add it to the beginning)
			while (amount != 0)
			{
				amount = amount - 1;
				s = s[len-1] + s;
				s.pop_back();
			}

		}
		else
		{
			amount = abs(amount) % len;
			// left shift (remove the first character of s and append it to the end)
			while (amount != 0)
			{
				amount = amount - 1;
				s.push_back(s[0]);
				s.erase(0, 1);
			}
		}
	}

	return s;
}


void stringShift_run(void)
{
	{
		string str = "abc";
		vector<int> f({0,1});
		vector<int> s({1,2});
		vector<vector<int>> shift;
		shift.push_back(f);
		shift.push_back(s);
		stringShift(str, shift);

	}
}

/**
 * Hint #1
 * Intuitively performing all shift operations is acceptable due to the constraints.
 * Hint #2
 * You may notice that left shift cancels the right shift, so count the total left shift times 
 * (may be negative if the final result is right shift), and perform it once.
 */

