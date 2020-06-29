#pragma once

/*
 * Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
 * You can only see the k numbers in the window. Each time the sliding window moves right by one position. 
 * Return the max sliding window.
 *
 * Follow up:
 * Could you solve it in linear time?
 *
 * Example:
 * Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
 * Output: [3,3,5,5,6,7]
 * Explanation:
 *
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 *
 * Constraints:
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;


vector<int> maxSlidingWindow(vector<int>& nums, int k);
void maxSlidingWindow(void);

void maxSlidingWindow(void)
{
	{
		vector<int> input({ 1,3,-1,-3,5,3,6,7 });
		int k = 3;
		vector<int> expected({ 3,3,5,5,6,7 });
		vector<int> actual = maxSlidingWindow(input, k);

		if (expected.size() != actual.size())
		{
			cout << "FAILED" << endl;
			return;
		}
		for(int i=0; i<expected.size(); i++)
		{
			if (actual[i] != expected[i])
			{
				cout << "FAILED" << endl;
				return;
			}
		}
		cout << "PASSED" << endl;
	}
}

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	vector<int> result;
	deque<int> dq;

	for (int i = 0; i < k - 1; i++) {
		while (!dq.empty() && dq.back() < nums[i])
			dq.pop_back();
		dq.push_back(nums[i]);
	}

	for (int i = k - 1; i < nums.size(); i++)
	{
		while (!dq.empty() && dq.back() < nums[i])
			dq.pop_back();
		dq.push_back(nums[i]);

		result.push_back(dq.front());

		if (nums[i - k + 1] == dq.front())
			dq.pop_front();
	}

	return result;
}
