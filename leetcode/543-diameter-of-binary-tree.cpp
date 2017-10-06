/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
 public:
  int diameterOfBinaryTree(TreeNode* root)
  {
    int maxlen = 0;
    postorder(root, maxlen);
    return maxlen;
  }

  int postorder(TreeNode* cur, int& maxlen)
  {
    if (!cur) return -1;
    int l = 1 + postorder(cur->left, maxlen);
    int r = 1 + postorder(cur->right, maxlen);
    if (l + r > maxlen) maxlen = l + r;
    return max(l, r);
  }
};
