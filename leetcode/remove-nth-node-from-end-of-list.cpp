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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!n || !head) return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *a = dummy;
    ListNode *b = head;

    for (int i = 0; i < n; ++i)
      b = b->next;
    for (; b; b = b->next)
      a = a->next;

    ListNode *c = a->next;
    a->next = a->next->next;
    delete c;

    c = dummy->next;
    delete dummy;

    return c;
  }
};
