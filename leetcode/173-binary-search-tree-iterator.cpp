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
 public:
  BSTIterator(TreeNode *root)
  {
    for (TreeNode* n = root; n; n = n->left)
      stk_.push_back(n);
  }

  /** @return whether we have a next smallest number */
  bool hasNext()
  {
    return stk_.size();
  }

  /** @return the next smallest number */
  int next()
  {
    TreeNode* ret = stk_.back();
    stk_.pop_back();
    for (TreeNode* n = ret->right; n; n = n->left)
      stk_.push_back(n);
    return ret->val;
  }

 private:
  vector<TreeNode*> stk_;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
