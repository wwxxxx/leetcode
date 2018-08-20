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
        queue<TreeLinkNode *> q;
        q.push(root);
        TreeLinkNode *head, *last;
        while (!q.empty())
        {
            head = last = q.front();
            q.pop();
            while (last != nullptr && !q.empty())
            {
                last = last->next = q.front();
                q.pop();
            }
            while (head != nullptr)
            {
                if (head->left)
                    q.push(head->left);
                if (head->right)
                    q.push(head->right);
                head = head->next;
            }
        }

        while (root)
        {
            TreeLinkNode dummy(-1);
            TreeLinkNode *pre = &dummy, *cur = root;
            while (cur != nullptr)
            {
                if (cur->left != nullptr)
                {
                    pre->next = cur->left;
                    pre = pre->next;
                }
                if (cur->right)
                {
                    pre->next = cur->right;
                    pre = pre->next;
                }
            }
            root = dummy.next;
        }
    }
};