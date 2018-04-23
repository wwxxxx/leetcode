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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        int carry = (l1->val + l2->val) / 10;
        ListNode *l3 = new ListNode((l1->val + l2->val) % 10);
        ListNode *tail = l3;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 || l2 || carry)
        {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            ListNode *t = new ListNode(sum % 10);
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
            tail->next = t;
            tail = t;
        }
        return l3;
    }
};