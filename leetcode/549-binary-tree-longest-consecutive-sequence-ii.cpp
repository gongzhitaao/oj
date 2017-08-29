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
  int longestConsecutive(TreeNode* root)
  {
    int maxlen = 0;
    if (root) postorder(root, maxlen);
    return maxlen;
  }

  tuple<int, int> postorder(TreeNode* node, int& maxlen)
  {
    int lin = 0, lout = 0, rin = 0, rout = 0;
    int d;
    if (node->left) {
      tie(lin, lout) = postorder(node->left, maxlen);
      d = node->val - node->left->val;
      if (1 == d) lin = 0;
      else if (-1 == d) lout = 0;
      else lin = lout = 0;
    }
    if (node->right) {
      tie(rin, rout) = postorder(node->right, maxlen);
      d = node->val - node->right->val;
      if (1 == d) rin = 0;
      else if (-1 == d) rout = 0;
      else rin = rout = 0;
    }
    int cur = 1 + max(lin + rout, lout + rin);
    if (cur > maxlen) maxlen = cur;
    return {1 + max(lin, rin), 1 + max(lout, rout)};
  }
};
