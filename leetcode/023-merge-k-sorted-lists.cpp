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
    struct cmp {
      bool operator()(ListNode* a, ListNode* b)
      { return a->val > b->val; }
    };
    priority_queue<ListNode*, vector<ListNode*>, cmp> q;
    for (auto lst : lists)
      if (lst) q.push(lst);

    ListNode* head = new ListNode(0);
    for (ListNode* cur = head; q.size(); cur = cur->next) {
      ListNode* t = q.top(); q.pop();
      cur->next = t;
      if (t->next) q.push(t->next);
    }
    ListNode* tmp = head->next;
    delete head;
    return tmp;
  }
};
