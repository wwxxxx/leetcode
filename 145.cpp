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
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        vector<int> ret;
        TreeNode *node = root;
        postorder(node, ret);
        return ret;
    }

    void postorder(TreeNode *root, vector<int> &ret)
    {
        if (root != nullptr)
        {
            postorder(root->left, ret);
            postorder(root->right, ret);
            ret.push_back(root->val);
        }
    }

    /*
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        vector<int> ret;
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        TreeNode *last = nullptr;
        while (!stk.empty() || cur != nullptr)
        {
            if (cur != nullptr)
            {
                stk.push(cur);
                cur = cur->left;
            }
            else
            {
                TreeNode *tmp = stk.top();
                if ((tmp->right != nullptr) && (tmp->right != last))
                    cur = tmp->right;
                else
                {
                    ret.push_back(tmp->val);
                    last = tmp;
                    stk.pop();
                }
            }
        }
        return ret;
    }
    */
};