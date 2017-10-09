class Solution
{
 public:
  /*
   * @param : the given tree
   * @return: the tree after swapping
   */
  TreeNode* bstSwappedNode(TreeNode* root)
  {
    TreeNode *p1 = nullptr, *p2 = nullptr;
    for (TreeNode *cur = root, *tmp = nullptr, *pre = nullptr; cur; ) {
      if (cur->left) {
        for (tmp = cur->left; tmp->right && tmp->right != cur; tmp = tmp->right)
          ;
        if (tmp->right) {
          tmp->right = nullptr;
          if (pre && pre->val > cur->val) {
            if (!p1) p1 = pre;
            p2 = cur;
          }
          pre = cur;
          cur = cur->right;
        } else {
          tmp->right = cur;
          cur = cur->left;
        }
      } else {
        if (pre && pre->val > cur->val) {
          if (!p1) p1 = pre;
          p2 = cur;
        }
        pre = cur;
        cur = cur->right;
      }
    }

    if (p1) swap(p1->val, p2->val);
    return root;
  }
};
