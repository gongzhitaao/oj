/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator
{
  stack<TreeNode*> trace_;

 public:
  BSTIterator(TreeNode *root)
  {
    for (TreeNode* cur = root; cur; cur = cur->left)
      trace_.push(cur);
  }

  /** @return whether we have a next smallest number */
  bool hasNext()
  {
    return trace_.size();
  }

  /** @return the next smallest number */
  int next()
  {
    TreeNode* elm = trace_.top();
    trace_.pop();
    for (TreeNode* cur = elm->right; cur; cur = cur->left)
      trace_.push(cur);
    return elm->val;
  }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
