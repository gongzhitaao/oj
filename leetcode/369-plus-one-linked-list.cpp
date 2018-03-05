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
    int carry = incr(head);
    if (carry) {
      ListNode* h = new ListNode(carry);
      h->next = head;
      head = h;
    }
    return head;
  }

  int incr(ListNode* cur)
  {
    if (!cur) return 1;
    int sum = cur->val + incr(cur->next);
    cur->val = sum % 10;
    return sum / 10;
  }
};
