#pragma once

/**
 * Write an algorithm to determine if a number is "happy".
 * A happy number is a number defined by the following process: Starting with any positive integer, 
 * replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), 
 * or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 *
 * Example:
 * Input: 19
 * Output: true
 * Explanation:
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 */


class Solution {
public:
	int squareDigit(int n) {
		int res = 0;
		while (n) {
			res = res + (n % 10)*(n % 10);
			n = n / 10;
		}
		return res;
	}
	bool isHappy(int n) {
		while (n != 1) {
			n = squareDigit(n);
			if (4 == n)
				return false;
		}
		return true;
	}
};

/**
 * Additional materials
 * https://en.wikipedia.org/wiki/Happy_number#10-happy_numbers
 * In base 10, there is only one cyhcle:
 * 4 => 16 => 37 => 58 => 89 => 145 => 42 => 20 => 4 => ...
 */


