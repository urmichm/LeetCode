#pragma once
/// Time Needed to Inform All Employees
/**
A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the company has is the one with headID.

Each employee has one direct manager given in the manager array where manager[i] is the direct manager of the i - th employee, manager[headID] = -1. Also it's guaranteed that the subordination relationships have a tree structure.

The head of the company wants to inform all the employees of the company of an urgent piece of news.He will inform his direct subordinates and they will inform their subordinates and so on until all employees know about the urgent news.

The i - th employee needs informTime[i] minutes to inform all of his direct subordinates(i.e After informTime[i] minutes, all his direct subordinates can start spreading the news).

Return the number of minutes needed to inform all the employees about the urgent news.

*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

static void run(void);
static int dfs(int id, vector<int>& manager, vector<int>& informTime, vector<vector<int>> adjList);
static int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime);


static void run(void)
{
	cout << "Time Needed to Inform All Employees" << endl;
	{
		int n = 6, headID = 2;
		vector<int> manager({ 2, 2, -1, 2, 2, 2 });
		vector<int> informTime({ 0, 0, 1, 0, 0, 0 });
		int result = 1;
		int actual = numOfMinutes(n,  headID, manager, informTime);
		cout << result << " " << (result == actual ? "EQ" : "NEQ") << "  " << actual << endl;
	}
	{
		int n = 15, headID = 0;
		vector<int> manager({ -1, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 });
		vector<int> informTime({ 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 });
		int result = 3;
		int actual = numOfMinutes(n, headID, manager, informTime);
		cout << result << " " << (result == actual ? "EQ" : "NEQ") << "  " << actual << endl;
	}
	{
		int n = 11, headID = 4;
		vector<int> manager({ 5, 9, 6, 10, -1, 8, 9, 1, 9, 3, 4 });
		vector<int> informTime({ 0, 213, 0, 253, 686, 170, 975, 0, 261, 309, 337 });
		int result = 2560;
		int actual = numOfMinutes(n, headID, manager, informTime);
		cout << result << " " << (result == actual ? "EQ" : "NEQ") << "  " << actual << endl;
	}
}

static int dfs(int id, vector<int>& manager, vector<int>& informTime, vector<vector<int>> adjList)
{
	int result = 0;
	if (informTime[id] == 0) return result;
	result = informTime[id];
	int sub_time = 0;

	for (int i : adjList[id]) {
		sub_time = max(sub_time, dfs(i, manager, informTime, adjList));
	}
	
	return result + sub_time;
}

static int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
{
	/* Create adjList manager->subordinates */
	vector<vector<int>> subordinates;
	for (int i = 0; i < n; i++) {
		vector<int> ith;
		subordinates.push_back(ith);
	}

	/* Use property of their relation to create list in O(n) !*/
	for (int i = 0; i < n; i++) {
		if (manager[i] != -1) {
			subordinates[manager[i]].push_back(i);
		}
	}

	return dfs(headID, manager, informTime, subordinates);
}