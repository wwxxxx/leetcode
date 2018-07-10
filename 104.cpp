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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int left = maxDepth(root->left) + 1;
        int right = maxDepth(root->right) + 1;
        return left > right ? left : right;
    }
};