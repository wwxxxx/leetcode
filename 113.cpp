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
    void helper(vector<vector<int>> &ret, vector<int> &vec, TreeNode *root, int sum)
    {
        if (root == nullptr)
            return;
        vec.push_back(root->val);
        if (sum == root->val && root->left == nullptr && root->right == nullptr)
        {
            ret.push_back(vec);
            vec.pop_back();
            return;
        }
        helper(ret, vec, root->left, sum - root->val);
        helper(ret, vec, root->right, sum - root->val);
        vec.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> ret;
        if (root == nullptr)
            return ret;
        vector<int> vec;
        helper(ret, vec, root, sum);
        return ret;
    }
};