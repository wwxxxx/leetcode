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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        if (root == nullptr)
            return ret;
        queue<TreeNode *> q;
        q.push(root);
        char flag = 1;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> temp;
            while (size--)
            {
                if (flag == 1)
                    temp.push_back(q.front()->val);
                else
                    temp.insert(temp.begin(), q.front()->val);
                if (q.front()->left != nullptr)
                    q.push(q.front()->left);
                if (q.front()->right != nullptr)
                    q.push(q.front()->right);
                q.pop();
            }
            flag = -flag;
            ret.push_back(temp);
        }
        return ret;
    }
};