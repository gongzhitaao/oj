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
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
  {
    TreeNode* cand = nullptr;
    for (TreeNode* cur = root; cur;) {
      if (cur->val <= p->val)
        cur = cur->right;
      else {
        cand = cur;
        cur = cur->left;
      }
    }
    return cand;
  }
};
