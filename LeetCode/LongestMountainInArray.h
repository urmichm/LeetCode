#pragma once

/**
 * Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:
 * 
 * B.length >= 3
 * There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
 * (Note that B could be any subarray of A, including the entire array A.)
 * 
 * Given an array A of integers, return the length of the longest mountain.
 *
 * Return 0 if there is no mountain.
 *  Follow up:
 *
 * Can you solve it using only one pass?
 * Can you solve it in O(1) space?
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/* Using State Machine */
int longestMountain(vector<int>& A) {
	if (A.size() < 3) return 0;
	
	const char GO_UP = 0;
	const char GO_DOWN = 1;
	const char SKIP = 2;
	char state = SKIP;
	int left = 0, right = 0;

	int result = 0;

	while (right < A.size()-1)
	{
		switch (state)
		{
			case GO_UP:
			{
				if (A[right] < A[right + 1])
					right++;
				else if (A[right] > A[right + 1])
					state = GO_DOWN;
				else { 
					left = right; 
					state = SKIP; 
				}
				break;
			}
			case GO_DOWN:
			{
				if (A[right] > A[right + 1])
					right++;
				else
				{
					result = max(result, right -left + 1);
					left = right;
					state = SKIP;
				}
				break;
			}
			case SKIP:
			{
				if (right + 1 < A.size())
				{
					if (A[right] < A[right + 1]) {
						right++;
						state = GO_UP;
					}
					else left = ++right;
				}
			}
		}
	}

	if (state == GO_DOWN)
	{
		if (right < A.size() - 1 && A[right] > A[right + 1])
			right++;
		result = max(result, (right - left + 1));
	}
	
	return result;
}



void longestMountain(void)
{
	
	{
		vector<int> input({ 0,0,1,0,0,1,1,1,1,1 });
		int Output = 3;
		int Actual = longestMountain(input);
		cout << (Output == Actual ? "PASSED" : "FAILED") << endl;
	}
	{
		vector<int> input({ 0,1,2,3,4,5,4,3,2,1,0 });
		int Output = 11;
		int Actual = longestMountain(input);
		cout << (Output == Actual ? "PASSED" : "FAILED") << endl;
	}
	{
		vector<int> input({ 1,2,4,4,4,4,2,1 });
		int Output = 0;
		int Actual = longestMountain(input);
		cout << (Output == Actual ? "PASSED" : "FAILED") << endl;
		// Explanation: There is no mountain.
	}
	{
		vector<int> input({ 2, 1, 4, 7, 3, 2, 5 });
		int Output = 5;
		int Actual = longestMountain(input);
		cout << (Output == Actual ? "PASSED" : "FAILED") << endl;
		// Explanation : The largest mountain is[1, 4, 7, 3, 2] which has length 5.
	}
	{
		vector<int> input({ 2, 2, 2 });
		int Output = 0;
		int Actual = longestMountain(input);
		cout << (Output == Actual ? "PASSED" : "FAILED") << endl;
		// Explanation: There is no mountain.
	}
}

