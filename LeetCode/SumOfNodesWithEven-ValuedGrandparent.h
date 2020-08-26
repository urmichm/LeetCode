#pragma once

/**
 * Given a binary tree, return the sum of values of nodes with even-valued grandparent.  (A grandparent of a node is the parent of its parent, if it exists.)
 *
 * If there are no nodes with an even-valued grandparent, return 0.
 */

#include <queue>
using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
int sumEvenGrandparent(TreeNode* root);

int sumEvenGrandparent(TreeNode* root)
{
	queue<TreeNode*> q;
	queue<TreeNode*> e;
	int res = 0;

	if (root) q.push(root);
	while (!q.empty())
	{
		TreeNode* node = q.front();
		q.pop();
		if (node->left)  q.push(node->left);
		if (node->right) q.push(node->right);
		if (node->val % 2 == 0) e.push(node);
	}

	while (!e.empty()) {
		TreeNode* gp = e.front(); e.pop();
		if (gp->left)
		{
			if (gp->left->left) res += gp->left->left->val;
			if (gp->left->right) res += gp->left->right->val;
		}
		if (gp->right)
		{
			if (gp->right->left) res += gp->right->left->val;
			if (gp->right->right) res += gp->right->right->val;
		}
	}
	return res;
}
