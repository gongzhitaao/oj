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
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
  {
    unordered_map<int, UndirectedGraphNode*> visited;
    return dfs(node, visited);
  }

  UndirectedGraphNode* dfs(UndirectedGraphNode* cur,
                           unordered_map<int, UndirectedGraphNode*>& visited)
  {
    if (!cur) return nullptr;
    if (visited.find(cur->label) != visited.end()) return visited[cur->label];

    UndirectedGraphNode* cp = new UndirectedGraphNode(cur->label);
    visited[cp->label] = cp;

    for (auto* elm : cur->neighbors)
      cp->neighbors.push_back(dfs(elm, visited));

    return cp;
  }
};
