#pragma once

/* You need to find the largest value in each row of a binary tree. */

#include <iostream>
#include <vector>
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
 

static vector<int> largestValues(TreeNode*& root);
static void largestValues(void);

static vector<int> largestValues(TreeNode*& root)
{
	vector<int> res;
	bool flag = true;
	queue<TreeNode*> q1;
	queue<TreeNode*> q2;
	int localres = INT_MIN;

	if (root == nullptr) return res;

	q1.push(root);

	while (!q1.empty() || !q2.empty())
	{
		if (flag)
		{
			while (!q1.empty())
			{
				TreeNode* node = q1.front();
				q1.pop();
				if (node->left != nullptr)  q2.push(node->left);
				if (node->right != nullptr) q2.push(node->right);
				if (localres < node->val)   localres = node->val;
			}
		}
		else
		{
			while (!q2.empty())
			{
				TreeNode* node = q2.front();
				q2.pop();
				if (node->left != nullptr)  q1.push(node->left);
				if (node->right != nullptr) q1.push(node->right);
				if (localres < node->val)   localres = node->val;
			}
		}

		res.push_back(localres);
		localres = INT_MIN;
		flag = !flag;
	}
	return res;
}

static void largestValues(void)
{
	TreeNode* five = new TreeNode(5);
	TreeNode* three = new TreeNode(3);
	TreeNode* nine = new TreeNode(9);

	TreeNode* three2 = new TreeNode(3, five, three);
	TreeNode* two2 = new TreeNode(2, nullptr, nine);

	TreeNode* root = new TreeNode(1, three2, two2);

	vector<int> res = largestValues(root);
	/**
	Input:

		  1
		 / \
		3   2
	   / \   \
	  5   3   9

	Output: [1, 3, 9]
	*/
}