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
  ListNode *detectCycle(ListNode *head) {
    if (!head) return nullptr;
    ListNode *slow, *fast;
    for (slow = head, fast = head; ;) {
      if (!fast->next || !fast->next->next) return nullptr;
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) break;
    }
    for (slow = head; slow != fast;
         slow = slow->next, fast = fast->next) ;
    return slow;
  }
};
