#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::vector<int> traverse_inorder_nonrecursive(TreeNode* root) {
  std::vector<int> ret;
  stack<TreeNode *> s;
  for (TreeNode *n = root; n || !s.empty(); n = n->right) {
    for (; n; n = n->left) s.push(n);
    n = s.top(); s.pop();
    ret.push_back(n->val);
  }
  return ret;
}

std::vector<int> traverse_preorder_nonrecursive(TreeNode* root) {
  std::vector<int> ret;
  if (!root) return ret;

  stack<TreeNode *> s;
  for (s.push(root); !s.empty(); ) {
    TreeNode *n = s.top(); s.pop();
    ret.push_back(n->val);
    if (n->right) s.push(n->right);
    if (n->left) s.push(n->left);
  }

  return ret;
}
