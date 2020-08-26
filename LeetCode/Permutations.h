#pragma once
/**
 * Given a collection of distinct integers, return all possible permutations.
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> permute(vector<int>& nums);
vector<vector<int>> permute_rec(vector<int>& nums);

vector<vector<int>> std_permute(vector<int>& nums);
void permute(void);


// std libray
vector<vector<int>> std_permute(vector<int>& nums) 
{
	vector<vector<int>> result;

	sort(nums.begin(), nums.end());

	do {
		result.push_back(nums);
	} while (next_permutation(nums.begin(), nums.end()));

	return result;
}

vector<vector<int>> permute(vector<int>& nums)
{
	vector<vector<int>> result = permute_rec(nums);


	return result;
}
vector<vector<int>> permute_rec(vector<int>& nums)
{
	vector<vector<int>> result;
	if (nums.size() == 0)
		return result;
	if (nums.size() == 1)
	{
		result.push_back(nums);
		return result;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		int front = nums[i];
		nums.erase(nums.begin()+i, nums.begin() + i + 1);

		vector<vector<int>> rec = permute_rec(nums);
		for (auto v : rec)
		{
			v.insert(v.begin(), front);
			result.push_back(v);
		}
		nums.insert(nums.begin() + i, front);
	}

	return result;
}


void permute(void)
{
	vector<int> input({ 1,2,3 });
	// vector<vector<int>> expected({ {1,2,3}, {1,3,2}, {2,1,3}, {2,3,1}, {3,1,2}, {3,2,1} });
	vector<vector<int>> actual = permute(input);

	for (auto v : actual)
	{
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}


/// Additional Notes:
/// Heap's Algorithm is comming soon
