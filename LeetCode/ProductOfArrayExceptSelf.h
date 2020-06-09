#pragma once
/**
 * Product of Array Except Self
 * Given an array nums of n integers where n > 1,  
 * return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 *
 * Example:
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 *
 * Constraint: 
 *	It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.
 *
 * Note: Please solve it without division and in O(n).
 * 
 * Follow up:
 *	Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
 */

#include <vector>
#include <algorithm>
using namespace std;

// no division
// Time: O(n)
// Space O(1) (The output array does not count)
// hint: use left- and right-products 
vector<int> productExceptSelf_division(vector<int>& nums)
{
	vector<int> output(nums.size(), 0);
	int prd = 1;
	int zeros = 0;
	for (int n : nums)
		if (n != 0) prd = prd * n;
		else        zeros++;

	if (zeros > 1) return output;

	if (1 == zeros)
	{
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] == 0)
			{
				output[i] = prd;
				break;
			}
		return output;
	}

	for (int i = 0; i < nums.size(); i++)
		output[i] = prd / nums[i];

	return output;
}
