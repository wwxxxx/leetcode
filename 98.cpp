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
    bool helper(TreeNode *root, TreeNode *minNode, TreeNode *maxNode)
    {
        if (root == nullptr)
            return true;
        if (minNode != nullptr && root->val <= minNode->val ||
            maxNode != nullptr && root->val >= maxNode->val)
            return false;
        return helper(root->left, minNode, root) && helper(root->right, root, maxNode);
    }

    bool isValidBST(TreeNode *root)
    {
        return helper(root, nullptr, nullptr);
    }

    /*
    bool isValidBST(TreeNode *root)
    {
        bool res = true;
        TreeNode *cur = root, *parent = NULL, *pre = NULL;
        while (cur)
        {
            if (!cur->left)
            {
                if (parent && parent->val >= cur->val)
                    res = false;
                parent = cur;
                cur = cur->right;
            }
            else
            {
                pre = cur->left;
                while (pre->right && pre->right != cur)
                    pre = pre->right;
                if (pre->right != cur)
                {
                    pre->right = cur;
                    cur = cur->left;
                }
                else
                {
                    if (parent->val >= cur->val)
                        res = false;
                    parent = cur;
                    pre->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return res;
    }
    */
};