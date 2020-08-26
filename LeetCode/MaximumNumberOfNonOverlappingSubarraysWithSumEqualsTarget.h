#pragma once

/***
 * Given an array nums and an integer target.
 *
 * Return the maximum number of non-empty non-overlapping subarrays 
 * such that the sum of values in each subarray is equal to target.
 */

#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;

static int  maxNonOverlapping(vector<int>& nums, int target);
static void maxNonOverlapping(void);

static void maxNonOverlapping(void)
{
	{
		vector<int> nums({ -5,5,-4,5,4 });
		int target = 5;
		int expected = 2;
		int actual = maxNonOverlapping(nums, target);
		cout << actual << " " << (actual == expected ? "EQ" : "NEQ") << " " << expected << endl;
	}
	{
		vector<int> nums({ 1,1,1,1,1 });
		int target = 2;
		int expected = 2;
		int actual = maxNonOverlapping(nums, target);
		cout << actual << " " << (actual == expected ? "EQ" : "NEQ") << " " << expected << endl;
	}
	{
		vector<int> nums({ -1,3,5,1,4,2,-9 });
		int target = 6;
		int expected = 2;
		int actual = maxNonOverlapping(nums, target);
		cout << actual << " " << (actual == expected ? "EQ" : "NEQ") << " " << expected << endl;
	}
	{
		vector<int> nums({ 0,0,0});
		int target = 0;
		int expected = 3;
		int actual = maxNonOverlapping(nums, target);
		cout << actual << " " << (actual == expected ? "EQ" : "NEQ") << " " << expected << endl;
	}

}


static int  maxNonOverlapping(vector<int>& nums, int target)
{
	unordered_set<int>s;
	int summ = 0;
	int result = 0;

	s.insert(summ);

	for (int i = 0; i < nums.size(); i++)
	{
		summ += nums[i];

		if (s.find(summ - target) != s.end())
		{
			result++;
			s.clear();
			summ = 0;
		}
		
		s.insert(summ);
	}
	s.clear();
	return result;
}

