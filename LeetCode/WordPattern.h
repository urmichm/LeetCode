#pragma once

/***
 * Given a pattern and a string str, find if str follows the same pattern.
 * Here follow means a full match, such that there is a bijection between 
 *                                  a letter in pattern and a non-empty word in str.
 *
 * Input: pattern = "abba", str = "dog cat cat dog"
 * Output: true
 * Input:pattern = "abba", str = "dog cat cat fish"
 * Output: false
 * Input: pattern = "aaaa", str = "dog cat cat dog"
 * Output: false
 * Input: pattern = "abba", str = "dog dog dog dog"
 * Output: false
 * Notes:
 *  You may assume pattern contains only lowercase letters, 
 *  and str contains lowercase letters that may be separated by a single space.
*/


#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;



bool wordPattern(string pattern, string str) 
{
	map<char, string> m;
	const unsigned int len = pattern.length();
	const char split_c = ' ';
	vector<string> words;
	
	string word = "";
	for (char c : str) 
	{
		if (c == split_c)
		{
			words.push_back(word);
			word = "";
		}
		else
		{
			word += c;
		}
	}
	if (word != "")
	{
		words.push_back(word);
		word = "";
	}
	

	if (len != words.size())
		return false;

	for (unsigned int i = 0; i < len; i++)
	{
		bool used = false;
		char p = pattern[i];
		
		word = words[i];
		map<char, string>::iterator it_pat = m.find(p);

		for (auto it_word = m.begin(); it_word != m.end(); it_word++)
			if (it_word->second == word)
				used = true;

		if (it_pat == m.end() && !used)
		{
			m[p] = word;
			continue;
		}
		else if (it_pat == m.end() && used)
			return false;
		else
		{
			if (it_pat->second != word)
				return false;
		}
	}
	return true;
}


void wordPattern(void)
{
	cout << "abba : dog cat cat dog " << (wordPattern("abba", "dog cat cat dog") == true ? "[passed]" : "[fail]") << endl;
	cout << "abba : dog cat cat fish " << (wordPattern("abba", "dog cat cat fish") == false ? "[passed]" : "[fail]") << endl;
	cout << "abba : dog cat dog" << (wordPattern("abba", "dog cat dog") == false ? "[passed]" : "[fail]") << endl;
	cout << "aaaa : dog cat cat dog " << (wordPattern("aaaa", "dog cat cat dog") == false ? "[passed]" : "[fail]") << endl;
	cout << "abba : dog dog dog dog " << (wordPattern("abba", "dog dog dog dog") == false ? "[passed]" : "[fail]") << endl;
}