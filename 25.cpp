#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == nullptr || k == 1)
            return head;
        ListNode *preHead = new ListNode(-1);
        preHead->next = head;
        ListNode *pre = preHead, *cur = preHead, *nex;
        int size = 0;
        while (cur->next != nullptr)
        {
            cur = cur->next;
            ++size;
        }
        while (size >= k)
        {
            cur = pre->next;
            nex = cur->next;
            for (int i = 1; i < k; ++i)
            {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            size -= k;
        }
        return preHead->next;
    }
};