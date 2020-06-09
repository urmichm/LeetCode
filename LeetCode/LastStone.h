#pragma once

#include <vector>
#include <algorithm>
using namespace std;

int lastStoneWeight(vector<int>& stones) 
{

	while (stones.size() > 1)
	{
		sort(stones.begin(), stones.end(), greater <>());
		int f = stones[0];
		stones.erase(stones.begin());
		int s = stones[0];
		stones.erase(stones.begin());
		if (f == s)
			continue;
		if (f > s)
			stones.push_back(f - s);
		else
			stones.push_back(s - f);
	}
	if (stones.size() == 1)
		return stones[0];
	return 0;
}


void lastStoneWeight_run(void)
{
	vector<int> test({ 2,7,4,1,8,1 });
	lastStoneWeight(test);
}


