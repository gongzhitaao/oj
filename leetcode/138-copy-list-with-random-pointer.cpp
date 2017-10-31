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
    unordered_map<RandomListNode *, RandomListNode *> visited;
    return dfs(head, visited);
  }

  RandomListNode *dfs(
    RandomListNode *node,
    unordered_map<RandomListNode *, RandomListNode *> &visited)
  {
    if (!node) return node;

    RandomListNode *new_node = new RandomListNode(node->label);
    visited[node] = new_node;

    if (visited.find(node->next) == visited.end())
      visited[node->next] = dfs(node->next, visited);
    new_node->next = visited[node->next];

    if (visited.find(node->random) == visited.end())
      visited[node->random] = dfs(node->random, visited);
    new_node->random = visited[node->random];

    return new_node;
  }
};
