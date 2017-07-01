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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
  {
    if (!l1) return l2;
    if (!l2) return l1;

    vector<int> v1, v2;

    for (ListNode* i = l1; i; i = i->next)
      v1.push_back(i->val);
    for (ListNode* i = l2; i; i = i->next)
      v2.push_back(i->val);

    int i = v1.size() - 1, j = v2.size() - 1;
    vector<int>& v = i > j ? v1 : v2;
    int k = v.size() - 1;

    int carry = 0;
    for (; i >= 0 && j >= 0; --i, --j, --k) {
      v[k] = v1[i] + v2[j] + carry;
      carry = 0;
      if (v[k] > 9) {
        carry = v[k] / 10;
        v[k] %= 10;
      }
    }

    for (; k >= 0 && carry; --k) {
      v[k] += carry;
      carry = 0;
      if (v[k] > 9) {
        carry = v[k] / 10;
        v[k] %= 10;
      }
    }

    ListNode* head = new ListNode(carry);
    ListNode* p = head;
    for (int val : v) {
      p->next = new ListNode(val);
      p = p->next;
    }

    if (carry) return head;
    return head->next;
  }
};
