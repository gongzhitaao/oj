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
  void recoverTree(TreeNode* root)
  {
    if (!root) return;
    morris_inorder(root);
  }

 private:
  void morris_inorder(TreeNode* root)
  {
    TreeNode *p0 = nullptr, *p1 = nullptr;
    for (TreeNode *cur = root, *back = nullptr, *pre = nullptr; cur; ) {
      if (!cur->left) {
        if (pre && pre->val > cur->val) {
          if (!p0) p0 = pre;
          p1 = cur;
        }
        pre = cur;
        cur = cur->right;
      } else {
        for (back = cur->left;
             back->right && back->right != cur;
             back = back->right) ;
        if (back->right) {
          back->right = nullptr;
          if (pre && pre->val > cur->val) {
            if (!p0) p0 = pre;
            p1 = cur;
          }
          pre = cur;
          cur = cur->right;
        } else {
          back->right = cur;
          cur = cur->left;
        }
      }
    }
    int v = p0->val;
    p0->val = p1->val;
    p1->val = v;
  }
};
