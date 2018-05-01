#include <bits/stdc++.h>
using namespace std;

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
	bool bfs(TreeNode *l, TreeNode *r)
	{
		if (l == nullptr || r == nullptr)
			return l == r;
		if (l->val != r->val)
			return false;
		return bfs(l->left, r->right) && bfs(l->right, r->left);
	}

	bool isSymmetric(TreeNode *root)
	{
		if (!root)
			return true;
		return bfs(root->left, root->right);
	}
};
