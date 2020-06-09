#pragma once
/**
 * Given an array nums, write a function to move all 0's to the end of it 
 * while maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]

 * Note:
 *  You must do this in-place without making a copy of the array.
 *  Minimize the total number of operations.
 *
 * https://leetcode.com/problems/move-zeroes/solution/
 */

#include <vector>
#include <iostream>
typedef unsigned int  uint;
using namespace std;

static void moveZeroes_bubble(vector<int>& nums);
static void moveZeroes_inser(vector<int>& nums);
void moveZeroes_adv(vector<int>& nums);

static void moveZeroes_run(void);


void moveZeroes_adv(vector<int>& nums)
{
	uint lastNonZeroIdx = 0;
	for (uint cur = 0; cur < nums.size(); cur++)
	{
		if (nums[cur] != 0)
		{
			swap(nums[lastNonZeroIdx++], nums[cur]);
		}
	}
}

static void moveZeroes_bubble(vector<int>& nums)
{
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			if (nums[j-1] == 0)
			{
				int t = nums[j - 1];
				nums[j - 1] = nums[j];
				nums[j] = t;
			}
		}
	}
}


static void moveZeroes_inser(vector<int>& nums)
{
	uint detected = 0;
	for (uint i = 0; i < nums.size() - detected; i++)
	{
		if (nums[i] == 0)
		{
			for (uint j = i; j <nums.size()-1 -detected; j++)
			{
				int t = nums[j ];
				nums[j] = nums[j+1];
				nums[j+1] = t;
			}
			i--;
			detected++;
		}
	}
}


static void moveZeroes_run(void)
{
	cout << "Move Zeroes" << endl;
	{
		vector<int> testcase({ 0,1,0,3,12 });
		vector<int> expected({ 1,3,12,0,0 });
		bool success = true;
		moveZeroes_inser(testcase);
		for (uint i = 0; i < testcase.size() && success; i++)
			if (testcase[i] != expected[i])
				success = false;
		cout << "test case 1: " << success << endl;
	}
	{
		vector<int> testcase({ 0,0,1 });
		vector<int> expected({ 1,0,0 });
		bool success = true;
		moveZeroes_inser(testcase);
		for (uint i = 0; i < testcase.size() && success; i++)
			if (testcase[i] != expected[i])
				success = false;
		cout << "test case 2: " << success << endl;
	}

	system("pause");
}
