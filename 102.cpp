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
    void helper(TreeNode *root, vector<vector<int>> &ret, int depth)
    {
        if (depth >= ret.size())
            ret.push_back({});
        ret[depth].push_back(root->val);
        if (root->left != nullptr)
            helper(root->left, ret, depth + 1);
        if (root->right != nullptr)
            helper(root->right, ret, depth + 1);
    }

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        if (root == nullptr)
            return ret;
        helper(root, ret, 0);
        return ret;
    }

    /*
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        if (root == nullptr)
            return ret;
        vector<int> cur;
        queue<TreeNode *> q, nodes;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            cur.push_back(node->val);
            if (node->left)
                nodes.push(node->left);
            if (node->right)
                nodes.push(node->right);
            if (q.empty())
            {
                q.swap(nodes);
                ret.push_back(cur);
                cur.clear();
            }
        }
        return ret;
    }
    */
};