/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  bool isPalindrome(ListNode* head) {
    ListNode *a = head, *b = head;

    while (b && b->next)
      a = a->next, b = b->next->next;

    ListNode *c;
    for (c = NULL; a;) {
      ListNode *t = a->next;
      a->next = c;
      c = a;
      a = t;
    }

    b = head;
    while (c && b) {
      if (c->val != b->val) return false;
      c = c->next;
      b = b->next;
    }

    return true;
  }
};
