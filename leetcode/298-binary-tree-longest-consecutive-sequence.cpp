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
    maxlen_ = 0;
    if (root) dfs(root, 1);
    return maxlen_;
  }

  void dfs(TreeNode* node, int len)
  {
    if (len > maxlen_) maxlen_ = len;
    for (TreeNode* child : {node->left, node->right}) {
      if (!child) continue;
      int cur = node->val - child->val;
      if (-1 == cur) dfs(child, len+1);
      else dfs(child, 1);
    }
  }

 private:
  int maxlen_;
};
