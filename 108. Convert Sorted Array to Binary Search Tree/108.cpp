#include <bits/stdc++.h>
using namespace std;

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
		TreeNode* helper(vector<int> &nums, int begin, int end)
		{
			if (end <= begin)
				return nullptr;
			int mid = (begin + end) / 2;
			TreeNode* root = new TreeNode(nums[mid]);
			root->left = helper(nums, begin, mid);
			root->right = helper(nums, mid + 1, end);
			return root;
		}

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
		return helper(nums, 0, nums.size());
    }
};
