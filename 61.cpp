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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || k == 0)
            return head;
        ListNode *fast = head, *slow = head;
        int n = 1, len = 1;
        for (int i = 0; i < k && fast->next != nullptr; i++, len++)
            fast = fast->next;
        if (len == k || k % len == 0)
            return head;
        else if (k > len)
        {
            fast = head;
            for (int i = 0; i < k % len; i++)
                fast = fast->next;
        }
        while (fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = nullptr;
        return head;
    }
};