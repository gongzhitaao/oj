/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution
{
 public:
  typedef UndirectedGraphNode Node;
  Node *cloneGraph(Node *node)
  {
    if (!node) return nullptr;
    unordered_map<int, Node*> v;
    return dfs(node, v);
  }

  Node *dfs(Node *src, unordered_map<int, Node*>& v)
  {
    if (v.find(src->label) != v.end())
      return v[src->label];
    Node *node = new Node(src->label);
    v[src->label] = node;
    for (Node *n : src->neighbors)
      node->neighbors.emplace_back(dfs(n, v));
    return node;
  }
};
