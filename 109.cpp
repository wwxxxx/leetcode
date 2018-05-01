#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  public:
	TreeNode *sortedListToBST(ListNode *head)
	{
		return sortedListToBST(head, nullptr);
	}

	TreeNode *sortedListToBST(ListNode *head, ListNode *tail)
	{
		if (head == tail)
			return nullptr;
		if (head->next == tail)
		{
			TreeNode *root = new TreeNode(head->val);
			return root;
		}
		ListNode *mid = head, *t = head;
		while (t != tail && t->next != tail)
		{
			mid = mid->next;
			t = t->next->next;
		}
		TreeNode *root = new TreeNode(mid->val);
		root->left = sortedListToBST(head, mid);
		root->right = sortedListToBST(mid->next, tail);
		return root;
	}
};