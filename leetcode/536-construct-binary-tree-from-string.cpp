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
  TreeNode* str2tree(string s)
  {
    stack<TreeNode*> stk;
    for (int i = 0; i < s.size(); ) {
      if (')' == s[i++]) {
        stk.pop();
        continue;
      }

      int j = i - (s[i - 1] != '(' && s[i - 1] != ')');
      for (; i < s.size() && '(' != s[i] && ')' != s[i]; ++i)
        ;

      TreeNode* cur = new TreeNode(stoi(s.substr(j, i - j)));
      if (stk.size()) {
        TreeNode* par = stk.top();
        if (par->left) par->right = cur;
        else par->left = cur;
      }
      stk.push(cur);
    }

    return stk.empty() ? nullptr : stk.top();
  }
};
