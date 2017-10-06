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
  ListNode* mergeKLists(vector<ListNode*>& lists)
  {
    if (lists.empty()) return nullptr;

    struct cmp {
      bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };

    priority_queue<ListNode*, vector<ListNode*>, cmp> q;

    for (ListNode* elm : lists)
      if (elm) q.push(elm);

    if (q.empty()) return nullptr;

    ListNode* head = q.top();
    q.pop();
    if (head->next) q.push(head->next);

    for (ListNode *cur = head, *ptr = nullptr; q.size(); cur = cur->next) {
      ptr = q.top();
      q.pop();
      cur->next = ptr;
      if (ptr->next) q.push(ptr->next);
    }

    return head;
  }
};
