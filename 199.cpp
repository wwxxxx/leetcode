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
    void helper(TreeNode *root, int level, vector<int> &vec)
    {
        if (root == nullptr)
            return;
        if (vec.size() < level)
            vec.push_back(root->val);
        helper(root->right, level + 1, vec);
        helper(root->left, level + 1, vec);
        return;
    }

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> vec;
        if (root == nullptr)
            return vec;
        helper(root, 1, vec);
        return vec;
    }
};