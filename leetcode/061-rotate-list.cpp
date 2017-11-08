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
  ListNode *rotateRight(ListNode *head, int k)
  {
    if (!head || !k) return head;

    int cnt = 1;
    ListNode *tail;
    for (tail = head; tail->next; tail = tail->next, ++cnt)
      ;

    k = cnt - (k % cnt);
    ListNode *par = head;
    for (int i = 0; i < k - 1; ++i, par = par->next)
      ;

    tail->next = head;
    head = par->next;
    par->next = nullptr;

    return head;
  }
};
