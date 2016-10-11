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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
  {
    for (int i = 0; i < inorder.size(); ++i)
      p_[inorder[i]] = i;
    return make_tree(inorder, postorder, 0, 0, inorder.size());
  }

  TreeNode* make_tree(const vector<int>& inorder,
                      const vector<int>& postorder,
                      int p, int q, int len)
  {
    if (0 == len) return nullptr;
    if (1 == len) return new TreeNode(inorder[p]);

    int val = postorder[q + len - 1];
    int k = p_[val];

    TreeNode* root = new TreeNode(val);
    int d = k - p;
    root->left = make_tree(inorder, postorder, p, q, d);
    root->right = make_tree(inorder, postorder, p + d + 1, q + d,
                            len - d - 1);
    return root;
  }

 private:
  map<int, int> p_;
};
