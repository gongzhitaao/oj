/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */

class BSTIterator
{
  stack<TreeNode*> trace_;

 public:
  /*
   * @param root: The root of binary tree.
   */
  BSTIterator(TreeNode* root)
  {
    for (TreeNode* cur = root; cur; cur = cur->left)
      trace_.push(cur);
  }

  /*
   * @return: True if there has next node, or false
   */
  bool hasNext()
  {
    return trace_.size();
  }

  /*
   * @return: return next node
   */
  TreeNode* next()
  {
    TreeNode* cur = trace_.top();
    trace_.pop();
    for (TreeNode* tmp = cur->right; tmp; tmp = tmp->left)
      trace_.push(tmp);
    return cur;
  }
};
