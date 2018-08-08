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
    vector<TreeNode *> helper(int start, int end)
    {

        vector<TreeNode *> ret;
        if (start > end)
        {
            ret.push_back(NULL);
            return ret;
        }
        for (int i = start; i <= end; ++i)
        {
            vector<TreeNode *> lefts = helper(start, i - 1);
            vector<TreeNode *> rights = helper(i + 1, end);
            for (int j = 0; j < lefts.size(); ++j)
            {
                for (int k = 0; k < rights.size(); ++k)
                {
                    TreeNode *node = new TreeNode(i);
                    node->left = lefts[j];
                    node->right = rights[k];
                    ret.push_back(node);
                }
            }
        }
        return ret;
    }

  public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return vector<TreeNode *>(0);
        return helper(1, n);
    }
};