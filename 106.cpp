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
    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int inBegin, int inEnd, int postBegin, int postEnd)
    {
        if (inBegin > inEnd || postBegin > postEnd)
            return nullptr;
        TreeNode *root = new TreeNode(postorder[postEnd]);
        int pos = distance(inorder.begin(), find(inorder.begin() + inBegin, inorder.begin() + inEnd, postorder[postEnd]));
        root->left = helper(inorder, postorder, inBegin, pos - 1, postBegin, postBegin - inBegin + pos - 1);
        root->right = helper(inorder, postorder, pos + 1, inEnd, postEnd - inEnd + pos, postEnd - 1);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};