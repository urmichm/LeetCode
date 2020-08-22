#pragma once

/**
 * Given a circular array C of integers represented by A, 
 * find the maximum possible sum of a non-empty subarray of C.
 * 
 * Here, a circular array means the end of the array connects to the beginning of the array.  
 * (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)
 * 
 * Also, a subarray may only include each element of the fixed buffer A at most once.  
 * (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j 
 *            with k1 % A.length = k2 % A.length.)
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static void run(void);
int maxSubarraySumCircular(vector<int>& A);



int maxSubarraySumCircular(vector<int>& A)
{
	const int N = A.size();
	if (0 == N) return 0;

	int straight = INT_MIN;
	int cyclic = INT_MIN;
	vector<int> kadane(A);
	straight = kadane[0] = A[0];

	for (int i = 1; i < N; i++) {
		kadane[i] = max(kadane[i - 1] + A[i], A[i]);
		straight = max(straight, kadane[i]);
	}
	// straight is the answer for non-cyclic araay

	vector<int> right_sum(A);
	// right_sum[i] = A[i] + A[i+1] + .. + A[N-1]
	right_sum[N - 1] = A[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		right_sum[i] = right_sum[i + 1] + A[i];
	}


	vector<int> maxright(A);
	maxright[N - 1] = right_sum[N - 1];
	for (int i = N - 1 - 1; i >= 0; i--) {
		maxright[i] = max(maxright[i + 1], right_sum[i]);
	}

	int leftsum = A[0];
	for (int i = 1; i <= N - 2; i++) {
		cyclic = max(cyclic, leftsum + maxright[i + 1]);
		leftsum += A[i];
	}

	return max(straight, cyclic);
}

static void run(void)
{
	{
		vector<int> A({ 5,-3,5 });
		int expected = 10;
		int actual = maxSubarraySumCircular(A);
		cout << actual << " " << (actual == expected ? "EQ" : "NEQ") << " " << expected << endl;
	}
	{
		vector<int> A({ 3,1,3,2,6 });
		int expected = 15;
		int actual = maxSubarraySumCircular(A);
		cout << actual << " " << (actual == expected ? "EQ" : "NEQ") << " " << expected << endl;
	}
	{
		vector<int> A({ 1,-2,3,-2 });
		int expected = 3;
		int actual = maxSubarraySumCircular(A);
		cout << actual << " " << (actual == expected ? "EQ" : "NEQ") << " " << expected << endl;
	}
	{
		vector<int> A({ 3,-1,2,-1 });
		int expected = 4;
		int actual = maxSubarraySumCircular(A);
		cout << actual << " " << (actual == expected ? "EQ" : "NEQ") << " " << expected << endl;
	}
	{
		vector<int> A({ 3,-2,2,-3 });
		int expected = 3;
		int actual = maxSubarraySumCircular(A);
		cout << actual << " " << (actual == expected ? "EQ" : "NEQ") << " " << expected << endl;
	}
	{
		vector<int> A({ -2, -3, -1 });
		int expected = -1;
		int actual = maxSubarraySumCircular(A);
		cout << actual << " " << (actual == expected ? "EQ" : "NEQ") << " " << expected << endl;
	}
}


