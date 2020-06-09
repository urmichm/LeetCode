#pragma once
/**
 * Diameter of Binary Tree
 * Given a binary tree, you need to compute the length of the diameter of the tree. 
 * The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
 * 
 * Example:
 * Given a binary tree
 *		  1
 *		 / \
 *		2   3
 *	   / \
 *	  4   5
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 *
 * Note: The length of path between two nodes is represented by the number of edges between them.
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

 /**
  * Definition for a binary tree node.
  */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

	int diameter;

	int goRec(TreeNode* node) {
		if (node == NULL)  return 0;

		int l = goRec(node->left);
		int r = goRec(node->right);

		diameter = max(diameter, l + r);

		return max(l, r) + 1;
	}

	int diameterOfBinaryTree(TreeNode* root) {
		diameter = 0;
		goRec(root);

		return diameter;
	}
};


// mess solution  
//class Solution {
//public:
//
//	void goRec(TreeNode* node, int* res, int* l, int* r) {
//		int ll, rl;
//
//		if (node == NULL) {
//			*res = *l = *r = 0;
//			return;
//		}
//
//		if (node->left == NULL) {
//			ll = 0;
//		}
//		else {
//			goRec(node->left, res, l, r);
//			ll = max(*l, *r) + 1;
//		}
//
//		if (node->right == NULL) {
//			rl = 0;
//		}
//		else {
//			goRec(node->right, res, l, r);
//			rl = max(*l, *r) + 1;
//		}
//
//		if (ll + rl > *res)
//			*res = ll + rl;
//		*l = ll;
//		*r = rl;
//
//		return;
//	}
//
//	int diameterOfBinaryTree(TreeNode* root) {
//		int res = 0;
//		int l, r;
//
//		goRec(root, &res, &l, &r);
//
//		return res;
//	}
//};