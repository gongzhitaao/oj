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
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> vec;
    if (!root) return vec;

    string c = to_string(root->val);
    if (!root->left && !root->right) {
      vec.push_back(c);
      return vec;
    }

    dfs(root->left, c, vec);
    dfs(root->right, c, vec);
    return vec;
  }

  void dfs(const TreeNode *root, const string &p, vector<string> &vec) {
    if (!root) return;

    string c = to_string(root->val);
    if (!root->left && !root->right)
      vec.push_back(p + "->" + c);

    dfs(root->left, p + "->" + c, vec);
    dfs(root->right, p + "->" + c, vec);
  }
};
