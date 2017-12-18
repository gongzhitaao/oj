/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
  TreeNode* sortedListToBST(ListNode* head)
  {
    return inorder(head, nullptr);
  }

  TreeNode* inorder(ListNode* head, ListNode* end)
  {
    if (head == end) return nullptr;

    ListNode *slow = head, *fast = head;
    for (; fast->next != end && fast->next->next != end;
         slow = slow->next, fast = fast->next->next)
      ;

    TreeNode *root = new TreeNode(slow->val);
    root->left = inorder(head, slow);
    root->right = inorder(slow->next, end);

    return root;
  }
};
