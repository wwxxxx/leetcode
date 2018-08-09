#include <bits/stdc++.h>
using namespace std;

static int x = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}();

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  public:
	bool helper(TreeNode *node1, TreeNode *node2)
	{
		if (node1 == nullptr && node2 == nullptr)
			return true;
		else if (node1 == nullptr || node2 == nullptr)
			return false;
		else
		{
			if (node1->val == node2->val)
				return helper(node1->left, node2->right) && helper(node1->right, node2->left);
			else
				return false;
		}
	}

	bool isSymmetric(TreeNode *root)
	{
		if (root == nullptr)
			return true;
		return helper(root->left, root->right);
	}
};