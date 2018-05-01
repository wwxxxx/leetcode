#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
	ListNode *reverseList(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode *rhead = nullptr;
		while (head != nullptr)
		{
			ListNode *t = head->next;
			head->next = rhead;
			rhead = head;
			head = t;
		}
		return rhead;
	}
};