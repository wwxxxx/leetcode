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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode *pA = headA;
        ListNode *pB = headB;
        int lenA = 0;
        int lenB = 0;
        while (pA->next != nullptr)
        {
            pA = pA->next;
            ++lenA;
        }
        while (pB->next != nullptr)
        {
            pB = pB->next;
            ++lenB;
        }
        if (pA != pB)
            return nullptr;
        pA = headA;
        pB = headB;
        int diff = abs(lenA - lenB);
        if (diff > 0)
        {
            if (lenA > lenB)
            {
                while (diff--)
                    pA = pA->next;
            }
            else if (lenA < lenB)
            {
                while (diff--)
                    pB = pB->next;
            }
        }
        while (pA != pB)
        {
            pA = pA->next;
            pB = pB->next;
        }
        return pA;
    }
};