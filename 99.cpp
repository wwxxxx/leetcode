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
    void recoverTree(TreeNode *root)
    {
        TreeNode *cur, *pre, *node1, *node2, *first, *second;
        node1 = node2 = first = nullptr;
        cur = root;
        while (cur)
        {
            if (cur->left == nullptr)
            {
                if (node1 == nullptr)
                    node1 = cur;
                else if (node2 == nullptr)
                    node2 = cur;
                else
                {
                    node1 = node2;
                    node2 = cur;
                }
                cur = cur->right;
            }
            else
            {
                pre = cur->left;
                while (pre->right != nullptr && pre->right != cur)
                    pre = pre->right;
                if (pre->right == nullptr)
                {
                    pre->right = cur;
                    cur = cur->left;
                    continue;
                }
                else
                {
                    pre->right = nullptr;
                    if (node2 == nullptr)
                        node2 = cur;
                    else
                    {
                        node1 = node2;
                        node2 = cur;
                        cur = cur->right;
                    }
                }
            }
            if (node1 && node2 && node1->val > node2->val)
            {
                if (first == nullptr)
                    first = node1;
                second = node2;
            }
        }
    }
};