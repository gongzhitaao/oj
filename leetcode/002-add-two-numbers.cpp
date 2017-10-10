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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
  {
    ListNode* head = new ListNode(0);
    ListNode *i, *j, *k;
    int c = 0;

    for (i = l1, j = l2, k = head; i && j;
         i = i->next, j = j->next, k = k->next) {
      int s = i->val + j->val + c;
      c = s / 10;
      k->next = new ListNode(s % 10);
    }
    for (; i; i = i->next, k = k->next) {
      int s = i->val + c;
      c = s / 10;
      k->next = new ListNode(s % 10);
    }
    for (; j; j = j->next, k = k->next) {
      int s = j->val + c;
      c = s / 10;
      k->next = new ListNode(s % 10);
    }
    if (c) k->next = new ListNode(c);

    i = head->next;
    delete head;

    return i;
  }
};
