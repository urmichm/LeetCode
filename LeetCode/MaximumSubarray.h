#pragma once
/**
 * Given an integer array nums, find the contiguous subarray (containing at least one number) 
 * which has the largest sum and return its sum.
 *
 * Example:
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6. 
 * Follow up:
 *
 * If you have figured out the O(n) solution,  
 * try coding another solution using the divide and conquer approach, 
 * which is more subtle.
 */
#include <vector>
#include <iostream>
#include <algorithm>  // to use max()
using namespace std;

typedef unsigned int  uint;

static int maxSubArray_brute(vector<int> nums);
static int maxSubArray_sliwin(vector<int> nums);
static int maxSubArray_dp(vector<int> nums);

static void MaximumSubarray_run();


static void MaximumSubarray_run()
{
	cout << "Maximum Subarray" << endl;
	int actual;

	int arr_1[] = { -2,1,-3,4,-1,2,1,-5,4 };
	std::vector<int> nums_1(arr_1, arr_1 + sizeof(arr_1) / sizeof(int));
	int expected_1 = 6;
	actual = maxSubArray_dp(nums_1);
	cout << "Test case 1 passed: " << (expected_1 == actual) << endl;


	int arr_2[] = { -2,-1,-3, 4,-1,-2, 1,-5,4 };
	std::vector<int> nums_2(arr_2, arr_2 + sizeof(arr_2) / sizeof(int));
	int expected_2 = 4;
	actual = maxSubArray_dp(nums_2);
	cout << "Test case 2 passed: " << (expected_2 == actual) << endl;


	system("pause");
}

static int maxSubArray_brute(vector<int> nums)
{
	int res = 0;
	if (0 == nums.size())
		return res;
	res = nums[0];
	for(uint i = 0; i < nums.size(); i++)
	{
		int s = nums[i];
		if (s > res)
			res = s;
		for (uint j = i + 1; j < nums.size(); j++)
		{
			s += nums[j];
			if (s > res)
				res = s;
		}
	}
	return res;
}

static int maxSubArray_sliwin(vector<int> nums)
{
	if (0 == nums.size()) return 0;
	int res_sum = nums[0];
	int window_sum = nums[0];

	for (int i = 1; i < nums.size(); i++)
	{
		if (window_sum + nums[i] < nums[i])
			window_sum = nums[i];
		else
			window_sum = window_sum + nums[i];

		if (window_sum > res_sum)
			res_sum = window_sum;
	}
	
	return res_sum;
}


static int maxSubArray_dp(vector<int> nums)
{
	int n = nums.size();
	if (n == 0)
		return 0;
	vector<int> dp(nums);
	int res = nums[0];
	for (int i = 1; i < n; ++i) {
		dp[i] = max(nums[i], nums[i] + dp[i - 1]);
		res = max(res, dp[i]);
	}
	
	//for (int i =0 ; i< nums.size(); i++)
	//	cout << nums[i]<< " ";
	//cout << endl;
	//for (int i = 0; i < dp.size(); i++)
	//	cout << dp[i] << " ";
	//cout << endl;

	return res;

}



