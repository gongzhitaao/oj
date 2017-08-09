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
  vector<TreeNode*> generateTrees(int n)
  {
    if (n < 1) return {};
    return build(1, n+1);
  }

  vector<TreeNode*> build(int start, int end)
  {
    if (start == end) return {nullptr};

    vector<TreeNode*> ret;
    for (int i = start; i < end; ++i) {
      vector<TreeNode*> lefts = build(start, i);
      vector<TreeNode*> rights = build(i+1, end);
      for (TreeNode* l : lefts) {
        for (TreeNode* r : rights) {
          TreeNode* root = new TreeNode(i);
          root->left = l;
          root->right = r;
          ret.push_back(root);
        }
      }
    }
    return ret;
  }
};
