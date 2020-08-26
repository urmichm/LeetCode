#pragma once

/**
 * Given a binary tree, return all root-to-leaf paths.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 * Input:
 *
 * 	   1
 * 	 /   \
 * 	2     3
 * 	 \
 * 	  5
 *
 * Output: ["1->2->5", "1->3"]
 *
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
 */

#include <vector>
#include <string>
using namespace std;



/* Definition for a binary tree node. */
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
} TreeNode;
 

static void recursive(TreeNode* node, string s, vector<string>& res);
static bool isLeave(TreeNode* node);
static vector<string> binaryTreePaths(TreeNode* root);

static vector<string> binaryTreePaths(TreeNode* root) 
{
	vector<string> res;
	if (root == nullptr)
		return res;

	string s = "" + to_string(root->val);
	if (isLeave(root) == true)
		res.push_back(s);

	recursive(root->left, s, res);
	recursive(root->right, s, res);

	return res;
}

static bool isLeave(TreeNode* node) {
	return
		(node->left == nullptr) && (node->right == nullptr);
}


static void recursive(TreeNode* node, string s, vector<string>& res) 
{
	if (node == nullptr) return;
	if (isLeave(node) == true) {
		s = s + "->" + to_string(node->val);
		res.push_back(s);
		return;
	}
	s = s + "->" + to_string(node->val);
	recursive(node->left, s, res);
	recursive(node->right, s, res);
	return;
}
