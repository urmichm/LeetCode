#pragma once

/**
 * Given an array A of positive integers, A[i] represents the value of the i-th sightseeing spot, 
 * and two sightseeing spots i and j have distance j - i between them.
 *
 * The score of a pair (i < j) of sightseeing spots is (A[i] + A[j] + i - j) : 
 * the sum of the values of the sightseeing spots, minus the distance between them.
 *
 * Return the maximum score of a pair of sightseeing spots.
 * 
 * Notes:
 *  2 <= A.length <= 50000
 *  1 <= A[i] <= 1000
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static int maxScoreSightseeingPair(vector<int>& A);
static void maxScoreSightseeingPair(void);

static void maxScoreSightseeingPair(void)
{
	vector<int> input({ 8, 1, 5, 2, 6 });
	int expeccted = 11;
	// Explanation : i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11
	int actual = maxScoreSightseeingPair(input);

	if (expeccted == actual)
		cout << "PASSED" << endl;
	else
		cout << "FAILED" << endl;

	return;
}

static int maxScoreSightseeingPair(vector<int>& A) 
{
	int res = 0;
	int prev = 0;

	res  = A[0];
	prev = A[0] - 1;

	for (int i=1; i <  A.size(); i++)
	{
		res = max(res, prev + A[i]);
		prev = max(prev, A[i]) - 1;
	}

	return res;
}
