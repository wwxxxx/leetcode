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
    TreeNode *helper(TreeNode *root, int &k)
    {
        TreeNode *target = nullptr;
        if (root->left != nullptr)
            target = helper(root->left, k);
        if (target == nullptr)
        {
            if (k == 1)
                target = root;
            --k;
        }
        if (target == nullptr && root->right != nullptr)
            target = helper(root->right, k);
        return target;
    }

    int kthSmallest(TreeNode *root, int k)
    {
        if (root == nullptr || k <= 0)
            return 0;
        TreeNode *ret = helper(root, k);
        return ret->val;
    }
};