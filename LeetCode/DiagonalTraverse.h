#pragma once

/**
 * Given a matrix of M x N elements (M rows, N columns), 
 * return all elements of the matrix in diagonal order
 */

#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& matrix);
static void run(void);



vector<int> findDiagonalOrder(vector<vector<int>>& matrix) 
{
	vector<int> result;

	/* Sum of indices of all numbers of a diagonal is the same 
	 * Store in a map diagonal numbers with Summ-of-indices as keys */
	map<int, vector<int>> map;

	for (int r = 0; r < matrix.size(); r++)
		for (int c = 0; c < matrix[r].size(); c++)
			map[r + c].push_back(matrix[r][c]);

	for (auto it = map.begin(); it != map.end(); it++)
		if (it->first % 2 == 1)
			for (int i = 0; i < it->second.size(); i++)
				result.push_back(it->second[i]);
		else
			for (int i = it->second.size() - 1; i >= 0; i--)
				result.push_back(it->second[i]);

	return result;
}

static void run(void)
{
	cout << "Diagonal Traverse" << endl;
	
	{
		vector<vector<int>> matrix
		(
			{
				{1, 2, 3, 4 },
				{5, 6, 7, 8},
				{9,10,11, 12}
			}
		);
		vector<int> expected({ 1,2,5,9,6,3,4,7,10,11,8,12 });
		vector<int> actual = findDiagonalOrder(matrix);
		string status = "ACCEPTED";
		if (expected.size() != actual.size())
		{
			status = "FAIL";
		}
		else
		{
			for (int i = 0; i < expected.size(); i++)
			{
				if (expected[i] != actual[i])
				{
					status = "FAIL";
					break;
				}
			}
		}
		cout << status << endl;
	}
		
	{
		vector<vector<int>> matrix
		(
			{
				{1, 2, 3, 4 },
			}
		);
		vector<int> expected({ 1,2,3,4 });
		vector<int> actual = findDiagonalOrder(matrix);
		string status = "ACCEPTED";
		if (expected.size() != actual.size())
		{
			status = "FAIL";
		}
		else
		{
			for (int i = 0; i < expected.size(); i++)
			{
				if (expected[i] != actual[i])
				{
					status = "FAIL";
					break;
				}
			}
		}
		cout << status << endl;
	}
	
	{
		vector<vector<int>> matrix
		(
			{
				{1}, 
				{2}, 
				{3}, 
				{4}
			}
		);
		vector<int> expected({ 1,2,3,4 });
		vector<int> actual = findDiagonalOrder(matrix);
		string status = "ACCEPTED";
		if (expected.size() != actual.size())
		{
			status = "FAIL";
		}
		else
		{
			for (int i = 0; i < expected.size(); i++)
			{
				if (expected[i] != actual[i])
				{
					status = "FAIL";
					break;
				}
			}
		}
		cout << status << endl;
	}

	{
		vector<vector<int>> matrix
		(
			{
				{1}
			}
		);
		vector<int> expected({ 1 });
		vector<int> actual = findDiagonalOrder(matrix);
		string status = "ACCEPTED";
		if (expected.size() != actual.size())
		{
			status = "FAIL";
		}
		else
		{
			for (int i = 0; i < expected.size(); i++)
			{
				if (expected[i] != actual[i])
				{
					status = "FAIL";
					break;
				}
			}
		}
		cout << status << endl;
	}

	{
		vector<vector<int>> matrix;
		vector<int> expected;
		vector<int> actual = findDiagonalOrder(matrix);
		string status = "ACCEPTED";
		if (expected.size() != actual.size())
		{
			status = "FAIL";
		}
		else
		{
			for (int i = 0; i < expected.size(); i++)
			{
				if (expected[i] != actual[i])
				{
					status = "FAIL";
					break;
				}
			}
		}
		cout << status << endl;
	}
}

