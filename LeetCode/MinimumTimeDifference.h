#pragma once

/**
 * Given a list of 24-hour clock time points in "Hour:Minutes" format, 
 * find the minimum minutes difference between any two time points in the list.
 * Example 1:
 * Input: ["23:59","00:00"]
 * Output: 1
 * Note:
 * The number of time points in the given list is at least 2 and won't exceed 20000.
 * The input time is legal and ranges from 00:00 to 23:59.
 */


#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;



static int findMinDifference(vector<string>& timePoints) 
{
	int result = 24 * 60;

	vector<int> timepoints;
	for (auto t : timePoints) {
		t = t.substr(0, 2) + t.substr(3);
		timepoints.push_back(stoi(t));
	}
	sort(timepoints.begin(), timepoints.end());

	const unsigned int len = timepoints.size();
	for (unsigned int i = 0; i < len && 0 != result; i++)
	{
		int first = timepoints[i];
		int second = timepoints[(i + 1) % len];

		if ((i + 1) % len == 0)
		{
			int t = first;
			first = second;
			second = t;
		}

		int f_mm = first % 100;
		int s_mm = second % 100;

		int d_hh = (second / 100) - (first / 100);
		int d_mm = 0;
		if (s_mm >= f_mm)
			d_mm = s_mm - f_mm;
		else
		{
			// turn 1 hour into 60 minutes
			d_hh = d_hh - 1;
			d_mm = 60 - f_mm + s_mm;
		}

		d_mm = d_hh * 60 + d_mm;
		if (d_mm > 12 * 60)
			d_mm = 24 * 60 - d_mm;
		if (result > d_mm)
			result = d_mm;
	}

	return result;
}


static void findMinDifference(void)
{
	
	{
		vector<string> input({ "17:41", "22:06", "20:59", "17:37", "04:14" });
		int res = findMinDifference(input);
		cout << res << " ? 4" << endl;
	}
	//{
	//	vector<string> input({ "00:00", "23:59", "16:45", "10:31" });
	//	int res = findMinDifference(input);
	//	cout << res << " ? 1" << endl;
	//}
	//{
	//	vector<string> input({ "00:00", "23:59", "16:45", "10:31", "00:00" });
	//	int res = findMinDifference(input);
	//	cout << res << " ? 0" << endl;
	//}
	//{
	//	vector<string> input({ "01:01","02:01","03:00" });
	//	int res = findMinDifference(input);
	//	cout << res << " ? 59" << endl;
	//}

}

