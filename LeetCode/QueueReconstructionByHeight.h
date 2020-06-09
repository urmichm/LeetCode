#pragma once

/**
 * Suppose you have a random list of people standing in a queue. 
 * Each person is described by a pair of integers (h, k), 
 * where h is the height of the person and k is the number of people in front of this person 
 * who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.
 *
 * Note:
 * The number of people is less than 1,100.
 *
 * Example
 * Input:
 * [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 * Output:
 * [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static void print(vector<vector<int>> data)
{
	for (auto d : data)
	{
		cout << "[ ";
		for (auto i : d)
			cout << i << " ";
		cout << " ]";
	}cout << endl;
}

static void reconstructQueue(void);
static vector<vector<int>> reconstructQueue(vector<vector<int>>& people);

static vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
{
	unsigned int total = people.size();
	// (h,k)
	vector<vector<int>> res(people.size());
	vector<vector<int>> shortests;  // used as queue
	int short_h = INT_MAX;
	int prev_h = -1;

	while (total != 0)
	{
		// get shortests
		for (int i = 0; i < people.size(); i++)
		{
			if (prev_h < people[i][0] && people[i][0] < short_h)
			{
				shortests.clear();
				shortests.push_back(people[i]);
				short_h = people[i][0];
			}
			else if (people[i][0] == short_h)
			{
				shortests.push_back(people[i]);
			}
		}
		// place shortest
		for (auto s : shortests)
		{
			unsigned int idx = s[1];
			unsigned int i = 0;
			for (i = 0; i <= idx; i++)
			{
				if (res[i].size() != 0)
					if (res[i][0] != s[0])
						idx++;
			}
			i = i - 1;
			res[i] = s;
		}

		total = total - shortests.size();
		prev_h = short_h;
		short_h = INT_MAX;
		shortests.clear();
	}

	return res;
}



static void reconstructQueue(void)
{
	{
		vector<vector<int>> people({ {7, 0}, {4, 4}, {7, 1}, {5, 0}, {4, 5}, {6, 1}, {5, 2} });
		vector<vector<int>> output({ {5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {4, 5}, {7, 1} });
		vector<vector<int>> actual = reconstructQueue(people);
		bool res = true;

		for (unsigned int i = 0; i < output.size(); i++)
		{
			if (actual[i][0] != output[i][0] || actual[i][1] != output[i][1])
			{
				res = false;
				break;
			}
		}

		cout << (res ? "[passed]" : "[failed]") << endl;
	}
	{
		vector<vector<int>> people({ {7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2} });
		vector<vector<int>> output({ {5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1} });

		vector<vector<int>> actual = reconstructQueue(people);

		bool res = true;

		for (unsigned int i = 0; i < output.size(); i++)
		{
			if (actual[i][0] != output[i][0] || actual[i][1] != output[i][1])
			{
				res = false;
				break;
			}
		}

		cout << (res ? "[passed]" : "[failed]") << endl;
	}
	{
		vector<vector<int>> people({ {2, 4}, {3, 4}, {9, 0}, {0, 6}, {7, 1}, {6, 0}, {7, 3}, {2, 5}, {1, 1}, {8, 0} });
		vector<vector<int>> actual = reconstructQueue(people);
		/* Try to make it yourself */
	}

	return;
}

/* Try to solve it from tallest to smallest */


//What can you say about the position of the shortest person ?
//If the position of the shortest person is i, how many people would be in front of the shortest person ?