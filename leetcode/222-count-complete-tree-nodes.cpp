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
  int countNodes(TreeNode* root)
  {
    int sum = 0;
    for (TreeNode* node = root; node; ) {
      int lh = 0, rh = 0;
      for (TreeNode* n = node->left; n; n = n->left) ++lh;
      for (TreeNode* n = node->right; n; n = n->left) ++rh;
      if (lh > rh) {
        sum += 1 << rh;
        node = node->left;
      } else {
        sum += 1 << lh;
        node = node->right;
      }
    }
    return sum;
  }
};
