/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution
{
 public:
  RandomListNode *copyRandomList(RandomListNode *head)
  {
    unordered_map<RandomListNode *, RandomListNode *> v;
    v[nullptr] = nullptr;
    return dfs(head, v);
  }

  RandomListNode *dfs(RandomListNode *cur,
                      unordered_map<RandomListNode *, RandomListNode *> &v)
  {
    if (v.find(cur) != v.end()) return v[cur];
    RandomListNode *ret = new RandomListNode(cur->label);
    v[cur] = ret;
    ret->next = dfs(cur->next, v);
    ret->random = dfs(cur->random, v);
    return ret;
  }
};
