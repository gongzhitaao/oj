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
  ListNode* removeElements(ListNode* head, int val) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    for (ListNode *p = dummy, *i = p->next; i; ) {
      if (i->val == val) {
        p->next = i->next;
        delete i;
        i = p->next;
      } else {
        p = i;
        i = i->next;
      }
    }

    ListNode *h = dummy->next;
    delete dummy;

    return h;
  }
};
