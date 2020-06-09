#pragma once


#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

static void InvertBinaryTree_run();
static TreeNode* InvertBinaryTree(TreeNode* root);


static TreeNode* InvertBinaryTree(TreeNode* root)
{
	queue<TreeNode*> q;

	if (NULL != root)
		q.push(root);

	while (!q.empty())
	{
		TreeNode* tmp = NULL;
		TreeNode* node = q.front();
		q.pop();

		if (node->left)
			q.push(node->left);
		if (node->right)
			q.push(node->right);

		tmp = node->left;
		node->left = node->right;
		node->right = tmp;
	}

	return root;
}


static void InvertBinaryTree_run()
{
	// The solution is trivial and based on BFS, test cases are ommitted
	// Input  [4,2,7,1,3,6,9]
	// Output [4,7,2,9,6,3,1]
}

/**
 * Complexity Analysis
 *
 * Since each node in the tree is visited / added to the queue only once, 
 * the time complexity is O(n)O(n), where nn is the number of nodes in the tree.
 *
 * Space complexity is O(n), since in the worst case, 
 * the queue will contain all nodes in one level of the binary tree. 
 * For a full binary tree, the leaf level has 
 *  ceil(n/2) = O(n) leaves.
 *
 */