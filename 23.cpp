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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        multimap<int, ListNode *> mp;
        for (auto i : lists)
            if (i != NULL)
                mp.insert(make_pair(i->val, i));
        ListNode *ret = NULL;
        ListNode *p = NULL;
        while (!mp.empty())
        {
            multimap<int, ListNode *>::iterator it = mp.begin();
            if (ret == NULL)
            {
                ret = it->second;
                p = ret;
            }
            else
            {
                p->next = it->second;
                p = p->next;
            }
            if (it->second->next != NULL)
                mp.insert(make_pair(it->second->next->val, it->second->next));
            mp.erase(it);
        }
        return ret;
    }
};