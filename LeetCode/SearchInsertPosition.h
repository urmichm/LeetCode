#pragma once
/**
 * Given a sorted array and a target value, return the index if the target is found. 
 * If not, return the index where it would be if it were inserted in order.
 * You may assume no duplicates in the array.
 * Example 1:
 * Input: {1,3,5,6}, 5
 * Output: 2
 * Example 2:
 * Input: {1,3,5,6}, 2
 * Output: 1
 * Example 3:
 * Input: {1,3,5,6}, 7
 * Output: 4
 * Example 4:
 * Input: {1,3,5,6}, 0
 * Output: 0
 */
#include <vector>
#include <iostream>
using namespace std;


static int searchInsert(vector<int>& nums, int target);
static void searchInsert(void);

static int searchInsert(vector<int>& nums, int target)
{
	int low = 0;
	int high = nums.size() - 1;
	while ( low <= high )
	{
		int mid = (low + high) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] > target)
			high = mid-1 ;
		else
			low = mid+1 ;
	}

 	return low;
}

static void searchInsert(void) 
{
	{
		vector<int> nums({ 3,5,7,9,10 });
		int target = 8;
		int expected = 3;
		int actual = searchInsert(nums, target);
		cout << (expected == actual ? "PASSED" : "FAIL") << endl;
	}
	{
		vector<int> nums({ 1, 3 });
		int target = 0;
		int expected = 0;
		int actual = searchInsert(nums, target);
		cout << (expected == actual ? "PASSED" : "FAIL") << endl;
	}
	{
		vector<int> nums({ 1, 3, 5, 6 });
		int target = 5;
		int expected = 2;
		int actual = searchInsert(nums, target);
		cout << (expected == actual ? "PASSED" : "FAIL") << endl;
	}
	{
		vector<int> nums({ 1, 3, 5, 6 });
		int target = 2;
		int expected = 1;
		int actual = searchInsert(nums, target);
		cout << (expected == actual ? "PASSED" : "FAIL") << endl;
	}
	{
		vector<int> nums({ 1, 3, 5, 6 });
		int target = 7;
		int expected = 4;
		int actual = searchInsert(nums, target);
		cout << (expected == actual ? "PASSED" : "FAIL") << endl;
	}
	{
		vector<int> nums({ 1, 3, 5, 6 });
		int target = 0;
		int expected = 0;
		int actual = searchInsert(nums, target);
		cout << (expected == actual ? "PASSED" : "FAIL") << endl;
	}
}

