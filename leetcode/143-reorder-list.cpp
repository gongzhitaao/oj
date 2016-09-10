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
  void reorderList(ListNode* head) {
    if (!head) return;

    ListNode *slow, *fast;
    for (slow = head, fast = head;
         fast->next && fast->next->next;
         slow = slow->next, fast = fast->next->next) ;

    ListNode *tail = nullptr;
    for (ListNode *cur = slow->next; cur;) {
      ListNode *next = cur->next;
      cur->next = tail, tail = cur, cur = next;
    }

    slow->next = nullptr;
    for (ListNode *i = head, *j = tail; i && j; ) {
      ListNode *a = i->next, *b = j->next;
      i->next = j, j->next = a;
      i = a, j = b;
    }
  }
};
