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
  ListNode* reverseBetween(ListNode* head, int m, int n)
  {
    if (!head) return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* mpre = dummy;
    int i;
    for (i = 0; i < m - 1; ++i)
      mpre = mpre->next;

    ListNode *pre, *cur;
    for (pre = mpre->next, cur = pre->next; i < n - 1; ++i) {
      ListNode* tmp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = tmp;
    }

    mpre->next->next = cur;
    mpre->next = pre;

    return dummy->next;
  }
};
