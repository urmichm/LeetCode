#pragma once

/**
 * Given an array of integers and an integer k, 
 * you need to find the total number of continuous subarrays whose sum equals to k.
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;


static void run(void);
int subarraySum(vector<int>& nums, int k);

static void run(void)
{
	{
		vector<int> nums({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
		int k = 0;
		int expected = 55;
		int actual = subarraySum(nums, k);
		cout << actual << " " << (actual == expected ? "EQ" : "NEQ") << " " << expected << endl;
	}
	{
		vector<int> nums({ 1 });
		int k = 0;
		int expected = 0;
		int actual = subarraySum(nums, k);
		cout << actual << " " << (actual == expected ? "EQ" : "NEQ") << " " << expected << endl;
	}
	{
		vector<int> nums({ 1,1,1 });
		//               0 1 2 3 
		int k = 2;
		int expected = 2;
		int actual = subarraySum(nums, k);
		cout << actual << " " << (actual == expected ? "EQ" : "NEQ") << " " << expected << endl;
	}
	{
		vector<int> nums({ -1,3,5,1, 4, 2,-9 });
		//               0 -1 2 7 8 12 14  5
		int target = 6;
		int expected = 3;
		int actual = subarraySum(nums, target);
		cout << actual << " " << (actual == expected ? "EQ" : "NEQ") << " " << expected << endl;
	}
}


/// sum(i,j)=sum(0,j)-sum(0,i), where sum(i,j) represents the sum of all the elements from index i to j-1.  */
int subarraySum(vector<int>& nums, int k)
{
	const int N = nums.size();
	int result = 0;
	int sum = 0;
	map<int, int> m; // sum , no.sum

	m[0] = 1;

	for (unsigned int i = 0; i < N; i++) {
		sum += nums[i];
		int seen = sum - k;
		map<int, int>::iterator it = m.find(seen);
		if (it != m.end()) {
			result += it->second;
		}
		m[sum] += 1;
	}

	return result;
}

