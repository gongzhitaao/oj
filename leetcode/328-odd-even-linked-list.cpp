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
  ListNode* oddEvenList(ListNode* head)
  {
    ListNode tmp0(0), tmp1(0);
    ListNode* odd = &tmp0;
    ListNode* even = &tmp1;
    ListNode* p = head;
    for (int i = 1; p; ++i) {
      ListNode*& cur = (i & 1) ? odd : even;
      cur->next = p;
      p = p->next;
      cur = cur->next;
      cur->next = nullptr;
    }
    odd->next = tmp1.next;
    return tmp0.next;
  }
};
