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
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int preBegin, int preEnd, int inBegin, int inEnd)
    {
        if (preBegin > preEnd || inBegin > inEnd)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[preBegin]);
        int pos = distance(inorder.begin(), find(inorder.begin() + inBegin, inorder.begin() + inEnd, preorder[preBegin]));

        root->left = helper(preorder, inorder, preBegin + 1, preBegin + pos - inBegin, inBegin, pos - 1);
        root->right = helper(preorder, inorder, preBegin + pos - inBegin + 1, preEnd, pos + 1, inEnd);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};