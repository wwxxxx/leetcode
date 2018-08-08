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
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        vector<int> ret;
        TreeNode *node = root;
        preorder(node, ret);
        return ret;
    }

    void preorder(TreeNode *root, vector<int> &ret)
    {
        if (root != nullptr)
        {
            ret.push_back(root->val);
            preorder(root->left, ret);
            preorder(root->right, ret);
        }
    }

    /*
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        vector<int> ret;
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        while (!stk.empty() || cur != nullptr)
        {
            if (cur != nullptr)
            {
                ret.push_back(cur->val);
                stk.push(cur);
                cur = cur->left;
            }
            else
            {
                TreeNode *tmp = stk.top();
                stk.pop();
                cur = tmp->right;
            }
        }
        return ret;
    }
    */
};