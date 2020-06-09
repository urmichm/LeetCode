#pragma once

/**
 * The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, 
 * such that each number is the sum of the two preceding ones, starting from 0 and 1.
*/
#include <algorithm>

int fib(int N);
int fib_loop(int N);

int fib(int N)
{
	double GoldenRatio = (1 + sqrt(5)) / 2;

	return (int)round(pow(GoldenRatio, N) / sqrt(5));
} 

int fib_loop(int N) 
{
	int n[] = { 0, 1, 0 };
	int idx = 2;
	if (N == 0) return n[0];
	if (N == 1) return n[1];

	for (; idx <= N; idx++)
	{
		// calculate curr 
		n[idx % 3] = n[(idx - 1) % 3] + n[(idx - 2) % 3];

	}
	// get prev idx
	--idx %= 3;
	return n[idx];
}