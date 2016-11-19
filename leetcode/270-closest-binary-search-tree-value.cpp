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
  int closestValue(TreeNode* root, double target)
  {
    int ret = root->val;
    for (TreeNode* n = root; n;
         n = n->val>target ? n->left : n->right) {
      if (abs(target-ret) > abs(target-n->val))
        ret = n->val;
    }
    return ret;
  }
};
