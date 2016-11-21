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
  ListNode* mergeKLists(vector<ListNode*>& lists)
  {
    if (lists.empty()) return nullptr;
    return merge(lists, 0, lists.size());
  }

  ListNode* merge(vector<ListNode*>& lists, int start, int len)
  {
    if (1 == len) return lists[start];
    int half = len / 2;
    ListNode* left = merge(lists, start, half);
    ListNode* right = merge(lists, start+half, len-half);
    ListNode* head = new ListNode(0);
    ListNode* cur;
    for (cur = head; left && right; cur = cur->next) {
      if (left->val < right->val) {
        cur->next = left;
        left = left->next;
      } else {
        cur->next = right;
        right = right->next;
      }
    }
    if (left) cur->next = left;
    else if (right) cur->next = right;
    cur = head->next;
    delete head;
    return cur;
  }
};
