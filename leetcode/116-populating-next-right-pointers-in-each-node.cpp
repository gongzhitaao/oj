/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *     int val;
 *     TreeLinkNode *left, *right, *next;
 *     TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
 public:
  void connect(TreeLinkNode* root) {
    for (TreeLinkNode* i = root; i; i = i->left) {
      if (!i->left) break;
      for (TreeLinkNode *j = i; j; j = j->next) {
        j->left->next = j->right;
        if (j->next)
          j->right->next = j->next->left;
      }
    }
  }
};
