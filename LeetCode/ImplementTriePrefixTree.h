#pragma once

/**
 * Implement a trie with insert, search, and startsWith methods.
 *
 * Example:
 *
 * Trie trie = new Trie();
 *
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");
 * trie.search("app");     // returns true
 *
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 */

#include <string>
#include <map>
using namespace std;

class Trie {

	struct data_s {
		map<char, struct data_s*> hash;
		char val;


		data_s(char c) {
			val = c;
			//        for(char c='a'; c<= 'z'; c++)
			//            hash[c] = nullptr;
			//        hash['\n'] = nullptr; // to idicate end of the word
		}
	};

	struct data_s* root;


public:

	/** Initialize your data structure here. */
	Trie()
	{
		root = new struct data_s(0);
		root->val = 0;
		//    for(char c='a'; c<= 'z'; c++)
		//        root->hash[c] = nullptr;
		//    root->hash['\n'] = nullptr;
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		struct data_s* node;
		if (root->hash[word[0]] == nullptr)
			root->hash[word[0]] = new struct data_s(word[0]);

		node = root->hash[word[0]];
		for (int i = 1; i < word.length(); i++) {
			if (node->hash[word[i]] == nullptr)
				node->hash[word[i]] = new struct data_s(word[i]);
			node = node->hash[word[i]];
		}
		node->hash['\n'] = new struct data_s('\n');
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		struct data_s* node = root;
		for (char c : word) {
			node = node->hash[c];
			if (node == nullptr)
				return false;
		}
		if (node->hash['\n'] == nullptr)
			return false;
		return true;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		struct data_s* node = root;
		for (char c : prefix) {
			node = node->hash[c];
			if (node == nullptr)
				return false;
		}

		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */