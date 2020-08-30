#pragma once
// Reorder Routes to Make All Paths Lead to the City Zero
/*
 * There are n cities numbered from 0 to n-1 and n-1 roads such that
 * there is only one way to travel between two different cities (this network form a tree).
 * Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.
 *
 * Roads are represented by connections where connections[i] = [a, b] represents a road from city a to b.
 *
 * This year, there will be a big event in the capital (city 0), and many people want to travel to this city.
 *
 * Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.
 *
 * It's guaranteed that each city can reach the city 0 after reorder.
 */

#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

static void run(void);
static int minReorder(int n, vector<vector<int>>& connections);



int minReorder(int n, vector<vector<int>>& connections) 
{
	int result = 0;
	
	if (connections.size() == 0 || n <= 0)
		return result;

	// v , adjacency vertices with imaginary flag (0 - edge exist, 1 - edge is imaginary)
	map<int, vector<pair<int, bool>>>  m;
	// Make n unvisited vertex-attributes
	vector<bool> visited(n);
	// Create graph
	for (auto edge : connections)
	{
		int v = edge[0];
		int u = edge[1];

		// edge v-u exist
		m[v].push_back(make_pair(u, false));

		// edge u-v is imaginary
		m[u].push_back(make_pair(v, 1));
	}

	// Go BFS from the root (edge 0)
	queue<int> q;
	q.push(0);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		visited[v] = true;

		for (vector<pair<int, bool>>::iterator it = m[v].begin(); it != m[v].end(); it++) {
			int u = it->first;
			if (visited[u] == false) {
				visited[u] = true;
				q.push(u);

				// Since we go from root to leafs, we flip edges that exist.
				// Goal is to reach from any v to root
				if (it->second == false)
					result++;
			}
		}
	}
	
	return result;
}

static void run(void)
{
	cout << "Reorder Routes to Make All Paths Lead to the City Zero" << endl;

	{
		vector<vector<int>> connections({ {1, 0}, {1, 2}, {3, 2}, {3, 4} });
		int n = 5;
		int expected = 2;
		int actual = minReorder(n, connections);
		cout << actual << " " << (actual == expected ? "EQ" : "NEQ") << " " << expected << endl;
	}
	{
		vector<vector<int>> connections({ {0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5} });
		int n = 6;
		int expected = 3;
		int actual = minReorder(n, connections);
		cout << actual << " " << (actual == expected ? "EQ" : "NEQ") << " " << expected << endl;
	}
	{
		vector<vector<int>> connections({ {1, 0}, {2, 0} });
		int n = 3;
		int expected = 0;
		int actual = minReorder(n, connections);
		cout << actual << " " << (actual == expected ? "EQ" : "NEQ") << " " << expected << endl;
	}

}
