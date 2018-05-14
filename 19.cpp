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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; i++)
            fast = fast->next;
        if (fast == nullptr)
        {
            slow = slow->next;
            return slow;
        }
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};