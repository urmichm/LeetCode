#pragma once

/**
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * You may assume no duplicate exists in the array.
 */

#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

static int findMin(vector<int>& nums);
static void run(void);


static int findMin(vector<int>& nums)
{
	const int N = nums.size();
	int left = 0;
	int right = nums.size() - 1;
	
	// easy case
	if (nums[left] <= nums[right])
		return nums[left];
	// 7,0
	// 4,5,6,7,0,1,2
	while (true) 
	{
		// check if nums[left] is min
		if (nums[left] < nums[(left + 1) % N] 
			&& nums[left] < nums[((left - 1 < 0) ? (N - 1) : (left - 1))]) {
			return nums[left];
		}
		if (nums[right] < nums[(right + 1) % N]
			&& nums[right] < nums[((right - 1 < 0) ? (N - 1) : (right - 1))]) {
			return nums[right];
		}

		int mid = left + ((right - left) / 2);

		if (nums[mid] > nums[left] && nums[mid] > nums[right])
			left = mid;
		else
			right = mid;
	}

	return nums[left];
}


static void run(void)
{
	cout << "Find Minimum in Rotated Sorted Array" << endl;
	{
		vector<int> nums({ 4,5,6,7,0,1,2 });
		int expected = 0;
		int actual = findMin(nums);
		cout << expected << " " << (actual == expected ? "EQ" : "NEQ") << " " << actual << endl;
	}
	{
		vector<int> nums({ 3,4,5,1,2 });
		int expected = 1;
		int actual = findMin(nums);
		cout << expected << " " << (actual == expected ? "EQ" : "NEQ") << " " << actual << endl;
	}
	{
		vector<int> nums({ 0,1 });
		int expected = 0;
		int actual = findMin(nums);
		cout << expected << " " << (actual == expected ? "EQ" : "NEQ") << " " << actual << endl;
	}
	{
		vector<int> nums({ 7,0 });
		int expected = 0;
		int actual = findMin(nums);
		cout << expected << " " << (actual == expected ? "EQ" : "NEQ") << " " << actual << endl;
	}
}

