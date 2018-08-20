#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

struct TreeLinkNode
{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
  public:
    void connect(TreeLinkNode *root)
    {
        if (root == nullptr)
            return;
        TreeLinkNode *pre = root, *cur = nullptr;
        while (pre->left != nullptr)
        {
            cur = pre;
            while (cur != nullptr)
            {
                cur->left->next = cur->right;
                if (cur->next != nullptr)
                    cur->right->next = cur->next->left;
                cur = cur->next;
            }
            pre = pre->left;
        }
    }
};