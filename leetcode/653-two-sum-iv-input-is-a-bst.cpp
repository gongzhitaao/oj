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
  bool findTarget(TreeNode* root, int k)
  {
    unordered_set<int> memo;
    return dfs(root, k, memo);
  }

 private:
  bool dfs(TreeNode *node, int k, unordered_set<int>& memo)
  {
    if (!node) return false;
    if (memo.find(k-node->val) != memo.end())
      return true;
    memo.insert(node->val);
    return dfs(node->left, k, memo) || dfs(node->right, k, memo);
  }
};
