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
    ListNode *insertionSortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *p = head->next;
        ListNode *tail = head;
        ListNode *begin = new ListNode(0);
        begin->next = head;
        while (p != nullptr)
        {
            ListNode *temp = begin->next, *pre = begin;
            while (temp != p && temp->val < p->val)
            {
                temp = temp->next;
                pre = pre->next;
            }
            if (temp == p)
                tail = p;
            else
            {
                tail->next = p->next;
                p->next = temp;
                pre->next = p;
            }
            p = tail->next;
        }
        head = begin->next;
        delete begin;
        return head;
    }
};