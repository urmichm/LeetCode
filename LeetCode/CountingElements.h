#pragma once

/**
 * Given an integer array arr, count element x such that x + 1 is also in arr.
 * If there're duplicates in arr, count them seperately.
 *
 * Example 1:
 * Input: arr = [1,2,3]
 * Output: 2
 * Explanation: 1 and 2 are counted cause 2 and 3 are in arr.
 *
 * Example 2:
 * Input: arr = [1,1,3,3,5,5,7,7]
 * Output: 0
 * Explanation: No numbers are counted, cause there's no 2, 4, 6, or 8 in arr.
 *
 * Example 3:
 * Input: arr = [1,3,2,3,5,0]
 * Output: 3
 * Explanation: 0, 1 and 2 are counted cause 1, 2 and 3 are in arr.
 *
 * Example 4:
 * Input: arr = [1,1,2,2]
 * Output: 2
 * Explanation: Two 1s are counted cause 2 is in arr.
 *
 * Constraints:
 * 1 <= arr.length <= 1000
 * 0 <= arr[i] <= 1000
*/


#include <vector>
#include <map>
#include <iostream>
using namespace std;


static int countElements(vector<int>& arr);
static void countElements_run(void);

static int countElements(vector<int>& arr)
{
	map<int, int>hmap;
	int res = 0;

	// hash map created element -> number of its appearances
	for (auto a : arr)
	{
		hmap[a]++;
	}
	
	// count the elements
	for (auto m : hmap)
	{
		if (hmap.find(m.first + 1) == hmap.end())
			continue;
		res += m.second;
	}
	return res;
}

static void countElements_run(void)
{
	cout << "Counting Elements" << endl;
	
	{
		vector<int> input({ 1,2,3 });
		int expected = 2;
		int actual = countElements(input);
		cout << "Test case 1: " << (actual == expected) << endl;
	}
	{
		vector<int> input({ 1, 1, 3, 3, 5, 5, 7, 7 });
		int expected = 0;
		int actual = countElements(input);
		cout << "Test case 2: " << (actual == expected) << endl;
	}
	{
		vector<int> input({ 1,3,2,3,5,0 });
		int expected = 3;
		int actual = countElements(input);
		cout << "Test case 3: " << (actual == expected) << endl;
	}
	{
		vector<int> input({ 1,1,2,2 });
		int expected = 2;
		int actual = countElements(input);
		cout << "Test case 4: " << (actual == expected) << endl;
	}
	{
		vector<int> input({ 1,1,2 });
		int expected = 2;
		int actual = countElements(input);
		cout << "Test case 5: " << (actual == expected) << endl;
	}
	system("pause");
}