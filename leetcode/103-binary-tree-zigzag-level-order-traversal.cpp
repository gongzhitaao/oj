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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root)
  {
    vector<vector<int>> ret;
    preorder(root, ret, 0);
    for (int i = 1; i < ret.size(); i += 2)
      reverse(ret[i].begin(), ret[i].end());
    return ret;
  }

  void preorder(TreeNode* node, vector<vector<int>>& ret, int dep)
  {
    if (!node) return;

    if (dep >= ret.size())
      ret.push_back({});

    ret[dep].push_back(node->val);
    preorder(node->left, ret, dep + 1);
    preorder(node->right, ret, dep + 1);
  }
};
