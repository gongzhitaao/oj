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

    for (ListNode *pre = dummy, *rear = pre->next; rear && rear->next;
         pre = rear, rear = rear->next) {
      int i = 1;
      for (ListNode *p = rear->next; i < k && p; ++i, p = rear->next) {
        rear->next = p->next;
        p->next = pre->next;
        pre->next = p;
      }

      if (i < k) {
        rear = pre->next;
        for (ListNode *p = rear->next; p; p = rear->next) {
          rear->next = p->next;
          p->next = pre->next;
          pre->next = p;
        }
        break;
      }
    }

    head = dummy->next;
    delete dummy;
    return head;
  }

};
