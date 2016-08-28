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
  void dfs(TreeNode* node, vector<int>& path, int remain)
  {
    path.push_back(node->val);
    remain -= node->val;

    if (!node->left && !node->right && !remain) {
      ret.push_back(path);
    } else {
      if (node->left) dfs(node->left, path, remain);
      if (node->right) dfs(node->right, path, remain);
    }
    path.pop_back();
  }

  vector<vector<int> > pathSum(TreeNode* root, int sum)
  {
    if (!root) return ret;
    vector<int> path;
    dfs(root, path, sum);
    return ret;
  }

 private:
  vector<vector<int> > ret;
};
