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
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        vector<int> ret;
        TreeNode *node = root;
        inorder(node, ret);
        return ret;
    }

    void inorder(TreeNode *root, vector<int> &ret)
    {
        if (root != nullptr)
        {
            inorder(root->left, ret);
            ret.push_back(root->val);
            inorder(root->right, ret);
        }
    }

    /*
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        vector<int> ret;
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        while (!stk.empty() || cur != nullptr)
        {
            if (cur)
            {
                stk.push(cur);
                cur = cur->left;
            }
            else
            {
                TreeNode *tmp = stk.top();
                stk.pop();
                ret.push_back(tmp->val);
                cur = tmp->right;
            }
        }
        return ret;
    }

    */
};