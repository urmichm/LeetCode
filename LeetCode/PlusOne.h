#pragma once

/**
 * Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
 *
 * The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
 *
 * You may assume the integer does not contain any leading zero, except the number 0 itself.
 *
 * Example 1:
 * Input: [1,2,3] 
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * Example 2:
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 */

#include <vector>
using namespace std;

static vector<int> plusOne(vector<int>& digits)
{
	int carry = 0, N = digits.size();
	int nd;

	nd = digits[N - 1] + 1;
	if (nd >= 10)
	{
		nd = nd % 10;
		carry = 1;
	}
	digits[N - 1] = nd;

	for (int i = digits.size() - 2; i >= 0 && carry != 0; i--)
	{
		nd = digits[i] + carry;
		if (nd >= 10)
		{
			nd = nd % 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		digits[i] = nd;
	}

	if (carry != 0)
		digits.insert(digits.begin(), carry);
	return digits;
}


/* Try to create a run function yourself */
