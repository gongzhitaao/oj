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
  bool isSubtree(TreeNode* s, TreeNode* t)
  {
    if (!s && !t) return true;
    if (!s || !t) return false;

    return dfs(s, t) ||
        isSubtree(s->left, t) ||
        isSubtree(s->right, t);
  }

  bool dfs(TreeNode* s, TreeNode* t)
  {
    if (!s && !t) return true;
    if (!s || !t) return false;

    return s->val == t->val &&
        dfs(s->left, t->left) &&
        dfs(s->right, t->right);
  }
};
