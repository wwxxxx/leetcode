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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ret;
        if (root == nullptr)
            return ret;
        vector<int> vec;
        queue<TreeNode *> q, nodes;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            vec.push_back(node->val);
            if (node->left != nullptr)
                nodes.push(node->left);
            if (node->right != nullptr)
                nodes.push(node->right);
            if (q.empty())
            {
                q.swap(nodes);
                ret.push_back(vec);
                vec.clear();
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};