#pragma once

/**
 * Find the sum of all left leaves in a given binary tree.
 *
 * Example:
 *
 *	 3
 *	/ \
 * 9  20
 *	 /  \
 *  15   7
 *
 * There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
 */

#include <queue>
using namespace std;
 
 // Definition for a binary tree node.
 struct TreeNode 
 {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

static int sumOfLeftLeaves(TreeNode* root);
static bool isLeave(TreeNode* node);

static bool isLeave(TreeNode* node) 
{
	return (node->left == nullptr) && (node->right == nullptr);
}

static int sumOfLeftLeaves(TreeNode* root)
{
	int sum = 0;
	if (root == nullptr)
		return sum;
	if (isLeave(root) == true)
		return sum;

	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		TreeNode* node = q.front();
		q.pop();
		if (node->left) {
			if (isLeave(node->left))
				sum += node->left->val;
			else
				q.push(node->left);
		}
		if (node->right)
			q.push(node->right);
	}

	return sum;
}


/* Try to make run function yourself */
