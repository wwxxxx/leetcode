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
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;
        while (!q.empty())
        {
            depth++;
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *temp = q.front();
                if (temp->left == nullptr && temp->right == nullptr)
                    return depth;
                if (temp->left != nullptr)
                    q.push(temp->left);
                if (temp->right != nullptr)
                    q.push(temp->right);
                q.pop();
            }
        }
        return 0;
    }
};