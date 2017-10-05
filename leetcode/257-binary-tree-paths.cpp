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
  vector<string> binaryTreePaths(TreeNode* root)
  {
    vector<string> ret;
    if (root) dfs(root, ret, "");
    return ret;
  }

  void dfs(TreeNode* cur, vector<string>& ret, string path)
  {
    path += "->" + to_string(cur->val);
    if (!cur->left && !cur->right) return ret.push_back(path.substr(2));
    if (cur->left) dfs(cur->left, ret, path);
    if (cur->right) dfs(cur->right, ret, path);
  }
};
