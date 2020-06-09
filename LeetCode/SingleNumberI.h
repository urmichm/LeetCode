#pragma once
/**
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 * Example 1:
 * Input: [2,2,1]
 * Output: 1
 * Example 2:
 * Input: [4,1,2,1,2]
 * Output: 4
 */

#include <vector>
using namespace std;

// Bit manipulation  XOR
// a XOR 0 = a
// a XOR a = 0
// a XOR b XOR a = a XOR a XOR b = 0 XOR b = b
// Time  O(n)
// Space O(1)
int singleNumber(vector<int>& nums)
{
	int result = 0;
	for (int i = 0; i < nums.size(); i++)
		result = result ^ nums[i];

	return result;
}

// You can also use HashTable
// Time O(n)
// Space O(n), we need additional space for HashTable

// Math solution 2*(a+b+c) - (a+a+b+b+c) = c
// Time: O(n+n) = O(n), we iterate over the all numbers in nums and over all unique numbers in set
// Space O(n), we need additional memory for the set

