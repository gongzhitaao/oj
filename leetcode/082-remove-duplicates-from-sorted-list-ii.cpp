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
  ListNode* deleteDuplicates(ListNode* head)
  {
    bool del = false;

    ListNode dummy(0);
    dummy.next = head;

    ListNode *cur, *pre, *tmp;
    for (cur = head, pre = &dummy, tmp = nullptr; cur && cur->next;) {
      if (cur->val == cur->next->val) {
        del = true;
        tmp = cur->next->next;
        delete cur->next;
        cur->next = tmp;
      } else {
        if (del) {
          del = false;
          tmp = cur->next;
          delete cur;
          pre->next = cur = tmp;
        } else {
          pre = cur;
          cur = cur->next;
        }
      }
    }

    if (del) {
      tmp = cur->next;
      delete cur;
      pre->next = tmp;
    }

    return dummy.next;
  }
};
