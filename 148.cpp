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
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        if (head1 == nullptr)
            return head2;
        if (head2 == nullptr)
            return head1;
        ListNode *ret, *p;
        if (head1->val < head2->val)
        {
            ret = head1;
            head1 = head1->next;
        }
        else
        {
            ret = head2;
            head2 = head2->next;
        }
        p = ret;
        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->val < head2->val)
            {
                p->next = head1;
                head1 = head1->next;
            }
            else
            {
                p->next = head2;
                head2 = head2->next;
            }
            p = p->next;
        }
        if (head1 != nullptr)
            p->next = head1;
        else if (head2 != nullptr)
            p->next = head2;
        return ret;
    }

    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        else
        {
            ListNode *fast = head, *slow = head;
            while (fast->next != nullptr && fast->next->next != nullptr)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            fast = slow;
            slow = slow->next;
            fast->next = nullptr;
            fast = sortList(head);
            slow = sortList(slow);
            return merge(fast, slow);
        }
    }
};