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
  ListNode* reverseList(ListNode* head)
  {
    if (!head) return head;

    for (ListNode *tail = head, *cur = tail->next, *t0 = nullptr, *t1 = nullptr;
         cur; cur = tail->next) {
      t0 = head;
      head = cur;
      t1 = cur->next;
      cur->next = t0;
      tail->next = t1;
    }

    return head;
  }
};
