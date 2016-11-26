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
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains
      at least one node. */
  Solution(ListNode* head)
  {
    for (ListNode* cur = head; cur; cur = cur->next)
      vals_.push_back(cur->val);
  }

  /** Returns a random node's value. */
  int getRandom()
  {
    return vals_[rand() % vals_.size()];
  }

 private:
  vector<int> vals_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
