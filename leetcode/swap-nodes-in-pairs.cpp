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
  ListNode* swapPairs(ListNode* head) {
    if (!head) return NULL;

    ListNode* foo = new ListNode(0);
    foo->next = head;
    for (ListNode* p = foo, * a = head, * b; a; ) {
      b = a->next;
      if (!b) break;

      ListNode *tmp = b->next;
      p->next = b;
      b->next = a;
      a->next = tmp;

      p = a;
      a = p->next;
    }

    ListNode *t = foo->next;
    delete foo;
    return t;
  }
};
