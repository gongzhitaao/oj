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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    int a = 0, b = 0;
    for (ListNode *i = headA; i; i = i->next) ++a;
    for (ListNode *i = headB; i; i = i->next) ++b;

    ListNode *pa = headA, *pb = headB;
    if (b - a < 0)
      for (int i = 0; i < a - b; ++i) pa = pa->next;
    else
      for (int i = 0; i < b - a; ++i) pb = pb->next;

    ListNode *ret = NULL;
    for ( ; pa && pb; pa = pa->next, pb = pb->next) {
      if (pa == pb) {
        ret = pa;
        break;
      }
    }

    return ret;
  }
};
