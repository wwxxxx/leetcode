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
    void reorderList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *mid = slow->next;
        slow->next = nullptr;
        ListNode *last = mid;
        ListNode *pre = nullptr;
        while (last != nullptr)
        {
            ListNode *next = last->next;
            last->next = pre;
            pre = last;
            last = next;
        }
        ListNode *cur = head;
        while (cur != nullptr && pre != nullptr)
        {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = pre->next;
            cur->next->next = next;
            cur = next;
        }
    }
};