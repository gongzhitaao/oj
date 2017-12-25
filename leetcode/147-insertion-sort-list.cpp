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
  ListNode* insertionSortList(ListNode* head)
  {
    ListNode dummy(0);

    for (ListNode *i = head, *tmp, *k; i;)
    {
      k = &dummy;
      for (ListNode *j = k->next; j && i->val > j->val; k = j, j = j->next)
        ;
      tmp = i->next;
      i->next = k->next;
      k->next = i;
      i = tmp;
    }

    return dummy.next;
  }
};
