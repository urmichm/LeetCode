#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

static string largestTimeFromDigits(vector<int>& A);
static void largestTimeFromDigits(void);


static void largestTimeFromDigits(void)
{
	{
		vector<int> A({1,2,3,4});
		string expected = "23:41";
		string actual = largestTimeFromDigits(A);
		cout << expected << " " << actual << " " << (actual == expected ? "OK" : "FAIL") << endl;
	}
	{
		vector<int> A({ 5,5,5,5 });
		string expected = "";
		string actual = largestTimeFromDigits(A);
		cout << expected << " " << actual << " " << (actual == expected ? "OK" : "FAIL") << endl;
	}
}

static string largestTimeFromDigits(vector<int>& A) 
{
	string result = "";
	int hr = -1, mr = -1;

	sort(A.begin(), A.end());

	do {
		int h = 0, m=0;
		h = 10 * A[0] + A[1];
		m = 10 * A[2] + A[3];
		if (h < 24 && m < 60)
		{
			if (h * 100 + m > hr * 100 + mr)
			{
				hr = h;
				mr = m;
			}
		}
	} while (std::next_permutation(A.begin(), A.end()));

	if (-1 != hr && -1 != mr) {
		if (hr < 10) result = result + "0";
		result = result + to_string(hr);
		result = result + ":";
		if (mr < 10) result = result + "0";
		result = result + to_string(mr);
	}
	return result;
}