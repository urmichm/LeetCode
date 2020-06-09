#pragma once
/***
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 *  ["ate","eat","tea"],
 *  ["nat","tan"],
 *  ["bat"]
 * ]
 *
 * Note:
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 */

#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

static void groupAnagrams_run(void);
static vector<vector<string>> groupAnagrams(vector<string>& strs);


static vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	vector<vector<string>> res;
	map<string, bool> hmap;

	// add to map 
	for (int i = 0; i < strs.size(); i++)
	{
		hmap[strs[i]] = true;
	}

	for (int i = 0; i < strs.size(); i++)
	{
		if (!hmap[strs[i]])
			continue;
		vector<string> group;
		group.push_back(strs[i]);
		hmap[strs[i]] = false;
		// anagrams of str
		char* arr = (char*)strs[i].c_str();
		do {
			string s(arr);
			if (hmap[s])
			{
				hmap[s] = false;
				group.push_back(s);
			}
		} while (next_permutation(arr, arr + strs[i].size()));
		// add group
		res.push_back(group);
	}

	return res;
}


static void groupAnagrams_run(void)
{
	vector<string> input({ "eat", "tea", "tan", "ate", "nat", "bat" });
	vector<vector<string>> res = groupAnagrams(input);

}




