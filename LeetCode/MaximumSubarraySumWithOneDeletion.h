#pragma once

/**
 * Given an array of integers, return the maximum sum for a non-empty subar ray (contiguous elements) 
 * with at most one element deletion. In other words, you want to choose a subarray and 
 * optionally delete one element from it so that there is still at least one element left and 
 * the sum of the remaining elements is maximum possible.
 *
 * Note that the subarray needs to be non-empty after deleting one element.
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static void maximumSum(void);
static int maximumSum(vector<int>& arr);

static void maximumSum(void)
{
	{
		vector<int> arr({ 1, -2 , 0 , 3 });
		int result = 4;
		int actual = maximumSum(arr);
		// Explanation : 
		// Because we can choose[1, -2, 0, 3] and drop - 2, thus the subarray[1, 0, 3] becomes the maximum value.
		cout << (result == actual ? "OK" : "FAIL") << "  " << actual << endl;
	}

	{
		vector<int> arr({ -7, 6, 1, 2, 1, 4, -1 });
		int result = 14;
		int actual = maximumSum(arr);
		cout << (result == actual ? "OK" : "FAIL") << "  " << actual << endl;
	}

	{
		vector<int> arr({ -1, 6, 1, 2, 1, 4, -7 });
		int result = 14;
		int actual = maximumSum(arr);
		cout << (result == actual ? "OK" : "FAIL") << "  " << actual << endl;
	}
	{
		vector<int> arr({ 1, -4, -5, -2, 5, 0, -1, 2 });
		int result = 7;
		int actual = maximumSum(arr);
		cout << (result == actual ? "OK" : "FAIL") << "  " << actual << endl;
	}

	{
		vector<int> arr({ 8, -1, 6, -7, -4, 5, -4, 7, -6 });
		int result = 17;
		int actual = maximumSum(arr);
		cout << (result == actual ? "OK" : "FAIL") << "  " << actual << endl;
	}
}

static int maximumSum(vector<int>& arr) 
{
	vector<int> dp_1(arr); // one deletion
	vector<int> dp_0(arr); //  no deletion
	const int N = arr.size();
	int res = 0;
	if (0 == N) return res;
	dp_0[0] = arr[0];
	dp_1[0] = arr[0];
	res = arr[0];
	for (int i = 1; i < N; i++) 
	{
		// Taking previous computed max1 value(which means value with atmost 1 removal of element)
		// Taking previous value of max0 value(which gives max value till one before the current element) AND removing the current value.
		// Starting out the array from the current element.
		dp_1[i] = max(dp_1[i - 1] + arr[i], max(arr[i], dp_0[i - 1]));

		dp_0[i] = max(dp_0[i - 1] + arr[i], dp_0[i - 1]);

		res = max(res, dp_1[i]);
	}

	return res;
}