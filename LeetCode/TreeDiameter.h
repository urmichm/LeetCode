#pragma once

#include<vector>
#include<iostream>
#include<unordered_set>
#include<queue>
#include<map>

using namespace std;


static int treeDiameter(vector<vector<int>>& edges);
static void bfs(int o, int* _max_depth, int* _farest_v);
static void addEdge(int v, int u);
static void run(void);

/* Adj List */
map<int, unordered_set<int>> adjlist;


static void addEdge(int v, int u) 
{
	if (adjlist.find(v) == adjlist.end()) {
		std::pair<int, unordered_set<int>> p;
		p.first = v;
		p.second.insert(u);
		adjlist.insert(p);
	}
	else {
		adjlist[v].insert(u);
	}

	adjlist[u].insert(v);
}

static void bfs(int o, int* _max_depth, int* _farest_v)
{
	int farest_v = o;
	int max_depth = 0;
	queue<int> q;
	map<int, int> depth; // vertex, depth
	
	for (auto it = adjlist.begin(); it != adjlist.end(); it++)
		depth[it->first] = INT_MAX;

	q.push(o);
	depth[o] = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto u : adjlist[v]) 
		{
			if (depth[v] + 1 < depth[u]) 
			{
				depth[u] = depth[v] + 1;
				q.push(u);
				if (depth[u] > max_depth) 
				{
					max_depth = depth[u];
					farest_v = u;
				}
			}
		}
	}
	if (_max_depth != nullptr)
		*_max_depth = max_depth;
	if (_farest_v != nullptr)
		*_farest_v = farest_v;

	return;
}

static int treeDiameter(vector<vector<int>>& edges) 
{
	unsigned int N = 0;
	int max_depth = 0; 
	int farest_v;
	if (edges.size() == 0) return max_depth;

	// Create AdjList
	for (auto edge : edges)
		addEdge(edge[0], edge[1]);
	
#ifdef DEBUG
	for (map<int, unordered_set<int>>::iterator it = adjlist.begin();
		it != adjlist.end(); it++)
	{
		cout << it->first << ": ";
		for (auto u : it->second)
			cout << u << " ";
		cout << endl;
	}
	// adjlist is ready :)
#endif // DEBUG
	
	/* Find the farest vertex from a random node */
	bfs(adjlist.cbegin()->first,  &max_depth, &farest_v);

	/* Find the max path length */
	bfs(farest_v, &max_depth, nullptr);

	adjlist.clear();
	return max_depth;
}



static void run(void)
{
	{
		vector<int> l1({ 0,1 });
		vector<int> l2({ 0,2 });
		vector<vector<int>> edges({ l1,l2 });
		int expected = 2;
		int actual = treeDiameter(edges);
		// Explanation :
		// A longest path of the tree is the path 1 - 0 - 2.
		cout << expected << " " << (expected == actual ? "EQ" : "NEQ") << "  " << actual << endl;
	}
	{
		vector<int> l1({ 0,1 });
		vector<int> l2({ 1,2 });
		vector<int> l3({ 2,3 });
		vector<int> l4({ 1,4 });
		vector<int> l5({ 4,5 });
		vector<vector<int>> edges({ l1,l2,l3,l4,l5 });
		int expected = 4;
		int actual = treeDiameter(edges);
		// Explanation:
		// A longest path of the tree is the path 3 - 2 - 1 - 4 - 5.
		cout << expected << " " << (expected == actual ? "EQ" : "NEQ") << "  " << actual << endl;
	}
	{
		vector<int> l1({ 0,1 });
		vector<int> l2({ 0,2 });
		vector<int> l3({ 1,3 });
		vector<int> l4({ 3,5 });
		vector<int> l5({ 2,4 });
		vector<int> l6({ 0,7 });
		vector<vector<int>> edges({ l1,l2,l3,l4,l5,l6 });
		int expected = 5;
		int actual = treeDiameter(edges);
		cout << expected << " " << (expected == actual ? "EQ" : "NEQ") << "  " << actual << endl;
	}

}
