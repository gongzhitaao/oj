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
  ListNode* sortList(ListNode* head)
  {
    return mergesort(head);
  }

  ListNode* mergesort(ListNode* start)
  {
    ListNode *pre = nullptr;
    ListNode *slow = start, *fast = start;
    for (; fast && fast->next;
         pre = slow, slow = slow->next, fast = fast->next->next)
      ;

    if (slow == fast) return slow;

    pre->next = nullptr;
    ListNode* left = mergesort(start);
    ListNode* right = mergesort(slow);

    ListNode dummy(0);
    ListNode *l = left, *r = right, *k = &dummy, *tmp = nullptr;

    for (ListNode **cur; l && r ; k = k->next) {
      if (l->val < r->val) cur = &l;
      else cur = &r;
      tmp = (*cur)->next;
      (*cur)->next = k->next;
      k->next = *cur;
      *cur = tmp;
    }

    for (; l; k = k->next) {
      tmp = l->next;
      l->next = k->next;
      k->next = l;
      l = tmp;
    }

    for (; r; k = k->next) {
      tmp = r->next;
      r->next = k->next;
      k->next = r;
      r = tmp;
    }

    return dummy.next;
  }
};
