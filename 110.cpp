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
    bool isBalanced(TreeNode *root, int &depth)
    {
        if (root == nullptr)
        {
            depth = 0;
            return true;
        }
        int left, right;
        if (isBalanced(root->left, left) && isBalanced(root->right, right))
        {
            int diff = abs(left - right);
            if (diff <= 1)
            {
                depth = max(left, right) + 1;
                return true;
            }
        }
        return false;
    }

    bool isBalanced(TreeNode *root)
    {
        int depth = 0;
        return isBalanced(root, depth);
    }
};