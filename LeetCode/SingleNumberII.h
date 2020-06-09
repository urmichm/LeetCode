#pragma once

/***
 * Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 *
 * Example 1:
 * Input: [2,2,3,2]
 * Output: 3
 *
 * Example 2:
 * Input: [0,1,0,1,0,1,99]
 * Output: 99
 */

#include<vector>
#include<map>
using namespace std;

static int singleNumber_HashMap(vector<int>& nums);
static int singleNumber(vector<int>& nums);

// HashMap Solution
static int singleNumber_HashMap(vector<int>& nums) 
{
	map<int, int> hmap;

	for (auto n : nums)
		hmap[n]++;

	for (auto m : hmap)
		if (m.second == 1)
			return m.first;

	return 0;
}

// Bit Manipulation
static int singleNumber(vector<int>& nums)
{
	// TODO: 
	return 0;
}