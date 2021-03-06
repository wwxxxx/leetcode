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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode small(0), big(0);
        ListNode *ps = &small, *pb = &big;
        while (head)
        {
            if (head->val < x)
                ps = ps->next = head;
            else
                pb = pb->next = head;
            head = head->next;
        }
        pb->next = NULL;
        ps->next = big.next;
        return small.next;
    }
};