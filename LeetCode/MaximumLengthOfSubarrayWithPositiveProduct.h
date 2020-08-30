#pragma once

/*
 * Given an array of integers nums, find the maximum length of a subarray 
 *                      where the product of all its elements is positive.
 *
 * A subarray of an array is a consecutive sequence of zero or more values taken out of that array.
 *
 * Return the maximum length of a subarray with positive product.
 */

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

static void run(void);
static int getMaxLen(vector<int>& nums);



// Make it in O(n)
static int getMaxLen(vector<int>& nums) 
{
	int result = 0;
	const int N = nums.size();
	if (N == 0)
		return result;

	// Goal:
	// 1. Split in subbarrays with no zeros and treat each subarray individually
	// 2. check if sub-array has even number of negatives, if yes get the product and compare agains the max
	// 2.1 if sub-array has odd number of negatives compare sub-sub-arrays [0, last_neg) and (first_neg, n]

	int n_negatives = 0;
	int zeroPos = -1;
	int first_neg = -1;


	for (int i = 0; i < N; i++) 
	{
		if (nums[i] == 0)
		{
			// Start of the subarray with non-null values
			zeroPos = i;
			// reset position of the first negative
			first_neg = -1;
			// reset number of negatives
			n_negatives = 0;
			// continue the loop, with new subarray with non-null numbers
			continue;
		}

		if(nums[i] < 0)
		{
			// Register the fist negative number, if it is not registered yet
			if (first_neg == -1)
				first_neg = i;
			// increment total number of negatives in the subarray with non-null values
			n_negatives = n_negatives + 1;
		}

		if (n_negatives % 2 == 0)
		{
			/* If the number of negatives is even, the product will be positive
			 * check the length of the subarray */
			result = max(result, i - zeroPos);
		}
		else
		{
			/* If number of negatives is odd, the longest subbarray could be one of two cases:
			 *  1. Subarray from the begining till the last negative number exclusivly. This case was checked in prev loop iteration [in IF block]. 
			 *  2. Subarray from the first negative number (exclusively) till the end of the subarray. [checked here, in ELSE block] */
			result = max(result, i - first_neg);
		}
	}

	return result;
}



static void run(void)
{
	{
		vector<int> nums({ 0,1,-2,-3,-4 });
		int expected = 3;
		int actual = getMaxLen(nums);
		cout << actual << " " << (actual == expected ? "EQ" : "NEQ") << " " << expected << endl;
		// The longest subarray with positive product is [1,-2,-3] which has a product of 6.
		// Notice that we cannot include 0 in the subarray since that'll make the product 0 which is not positive.
	}
	{
		vector<int> nums({ 1,-2,-3,4 });
		int expected = 4;
		int actual = getMaxLen(nums);
		cout << actual << " " << (actual == expected ? "EQ" : "NEQ") << " " << expected << endl;
		// The array nums already has a positive product of 24.
	}
	{
		vector<int> nums({ -1,-2,-3,0,1 });
		int expected = 2;
		int actual = getMaxLen(nums);
		cout << actual << " " << (actual == expected ? "EQ" : "NEQ") << " " << expected << endl;
	}
	{
		vector<int> nums({ -1,2 });
		int expected = 1;
		int actual = getMaxLen(nums);
		cout << actual << " " << (actual == expected ? "EQ" : "NEQ") << " " << expected << endl;
	}
	{
		vector<int> nums({ 1,2,3,5,-6,4,0,10 });
		int expected = 4;
		int actual = getMaxLen(nums);
		cout << actual << " " << (actual == expected ? "EQ" : "NEQ") << " " << expected << endl;
	}

}

