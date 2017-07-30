/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return build(nums, 0, nums.size());
  }

  TreeNode* build(const vector<int>& nums, int beg, int end) {
    if (beg >= end) return NULL;

    int mid = (beg + end) / 2;
    TreeNode* p = new TreeNode(nums[mid]);
    p->left = build(nums, beg, mid);
    p->right = build(nums, mid + 1, end);

    return p;
  }
};
