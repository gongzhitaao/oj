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
    if (!root) return;

    queue<TreeLinkNode *> q;
    q.push(NULL);

    for (TreeLinkNode *n = root; !q.empty(); ) {
      if (!n) {
        q.push(NULL);
      } else {
        n->next = q.front();
        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
      }
      n = q.front(); q.pop();
    }
  }
};
