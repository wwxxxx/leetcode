#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* helper(TreeNode* root){
		if (!root->left && !root->right)
			return root;

		if (!root->right){
			root->right = root->left;
			root->left = nullptr;
		}
		if (!root->left)
			return helper(root->right);

		TreeNode* lt = helper(root->left);
		TreeNode* rt = helper(root->right);
		lt->right = root->right;
		root->right = root->left;
		root->left = nullptr;

		return rt;
	}

	void flatten(TreeNode* root) {
		helper(root);
		return;
	}
};