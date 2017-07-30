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
  ListNode* reverseKGroup(ListNode* head, int k)
  {
    if (!head || 1 == k) return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    for (ListNode *p = dummy, *rear = p->next; rear && rear->next;
         p = rear, rear = rear->next) {
      if (reverse_k(p, k) < k)
        reverse_k(p, k);
    }

    head = dummy->next;
    delete dummy;
    return head;
  }

  inline int reverse_k(ListNode *pre, int k)
  {
    int cnt = 1;
    for (ListNode *rear = pre->next, *p = rear->next;
         cnt < k && p; ++cnt, p = rear->next) {
      rear->next = p->next;
      p->next = pre->next;
      pre->next = p;
    }
    return cnt;
  }

};
