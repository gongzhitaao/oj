/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
 public:
  void connect(TreeLinkNode *root) {
    for (TreeLinkNode *i = root, *start = nullptr; i;
         i = start, start = nullptr) {
      for (TreeLinkNode *j = i, *k = nullptr; j; j = j->next) {
        if (k) {
          if (j->left) k->next = j->left, k = k->next;
          if (j->right) k->next = j->right, k = k->next;
        } else {
          if (j->left) {
            start = k = j->left;
            if (j->right)
              k->next = j->right, k = k->next;
          } else if (j->right)
            start = k = j->right;
        }
      }
    }
  }
};
