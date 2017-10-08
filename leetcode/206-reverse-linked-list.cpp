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
    ListNode* pre = nullptr;
    for (ListNode* next = nullptr; head; head = next) {
      next = head->next;
      head->next = pre;
      pre = head;
    }
    return pre;
  }
};
