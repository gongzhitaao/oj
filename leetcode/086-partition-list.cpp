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
  ListNode* partition(ListNode* head, int x)
  {
    ListNode less(-1), geq(-1);
    ListNode *tail0 = &less, *tail1 = &geq;

    for (ListNode *cur = head, *tmp = nullptr; cur; cur = tmp) {
      tmp = cur->next;
      cur->next = nullptr;

      if (cur->val < x) {
        tail0->next = cur;
        tail0 = cur;
      } else {
        tail1->next = cur;
        tail1 = cur;
      }
    }

    tail0->next = geq.next;
    return less.next;
  }
};
