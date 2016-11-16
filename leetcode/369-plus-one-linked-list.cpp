/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
 public:
  ListNode* plusOne(ListNode* head)
  {
    int carry = increment(head);
    ListNode *ret = head;
    if (carry > 0) {
      ret = new ListNode(carry);
      ret->next = head;
    }
    return ret;
  }

  int increment(ListNode* node)
  {
    if (!node) return 1;
    int val = node->val + increment(node->next);
    node->val = val % 10;
    return val / 10;
  }
};
