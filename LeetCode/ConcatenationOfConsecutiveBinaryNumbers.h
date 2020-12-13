#pragma once

#include <iostream>
#include <string>
using namespace std;

/**
 * Given an integer n, return the decimal value of the binary string formed by 
 * concatenating the binary representations of 1 to n in order, modulo 10^9 + 7.
 */

static int concatenatedBinary(int n);
void run(void);

static int concatenatedBinary(int n) 
{
	cout << "number " << n << endl;

	long res = 0;
	long mod = 1e9 + 7;
	int shift = 0;

	for (int i = 1; i <= n; i++)	
	{
		if ((i & i - 1) == 0)
			shift ++;
		res = ((res << shift)%mod + i)%mod;
	}

	cout << "result " << res << endl;
	return res;

	// 0  0 - 0           f(0) = 0
	// 1  1 - 1           f(0) << 1 + 1
	// 6  2 - 110         f(1) << 2 + 2
	//27  3 - 11011       f(2) << 2 + 3
	//    4 - 11011100    f(3) << 3 + 4
	//    5 - 11011100101 f(4) << 3 + 5
}

void run(void)
{
	{
		int n = 1;
		int output = 1;
		// Explanation : "1" in binary corresponds to the decimal value 1.
		cout << (output == concatenatedBinary(n) ? "OK" : "KO") << endl;
	}
	{
		int n = 3;
		int output = 27;
		// In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
		// After concatenating them, we have "11011", which corresponds to the decimal value 27.
		cout << (output == concatenatedBinary(n) ? "OK" : "KO") << endl;
	}
	{
		int n = 12;
		int output = 505379714;
		cout << (output == concatenatedBinary(n) ? "OK" : "KO") << endl;
	}
}
