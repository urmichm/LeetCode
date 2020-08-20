#pragma once

/**
 * Given a binary tree root and an integer target, delete all the leaf nodes with value target.
 *
 *  Note that once you delete a leaf node with value target, 
 *  if it's parent node becomes a leaf node and has the value target, 
 *  it should also be deleted (you need to continue doing that until you can't).
 */

 
  /// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  
class Solution {
public:
	bool isLeaf(TreeNode* node)
	{
		return (node->left == nullptr) && (node->right == nullptr);
	}

	TreeNode* removeLeafNodes(TreeNode* node, int target)
	{
		if (node == nullptr) return nullptr;

		if (node->left) {
			if (isLeaf(node->left) && node->left->val == target) {
				delete (node->left);
				node->left = nullptr;
			}
			else {
				node->left = removeLeafNodes(node->left, target);
				if (node->left != nullptr &&
					isLeaf(node->left) && node->left->val == target) {
					delete (node->left);
					node->left = nullptr;
				}
			}
		}
		if (node->right) {
			if (isLeaf(node->right) && node->right->val == target) {
				delete (node->right);
				node->right = nullptr;
			}
			else {
				node->right = removeLeafNodes(node->right, target);
				if (node->right &&
					isLeaf(node->right) && node->right->val == target) {
					delete (node->right);
					node->right = nullptr;
				}
			}
		}

		if (isLeaf(node) && node->val == target) {
			// delete (node); 
			node = nullptr;
		}

		return node;
	}

};