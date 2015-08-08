/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
  void connect(UndirectedGraphNode* a, UndirectedGraphNode* b) {
    a->neighbors.push_back(b);
    // if (a != b) {
      // b->neighbors.push_back(a);
    // }
  }

  UndirectedGraphNode* initNodeFrom(UndirectedGraphNode* node, 
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*>& M,
    queue<UndirectedGraphNode*>& Q) {
    UndirectedGraphNode* ret = new UndirectedGraphNode(node->label); 
    if (!M.count(node)) {
      M[node] = ret;
      Q.push(node);
    }
    return ret;
  }


  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (node == NULL) {
      return NULL;
    }
    
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> M;
    queue<UndirectedGraphNode*> Q;

    UndirectedGraphNode* ret = initNodeFrom(node, M, Q);

    while (!Q.empty()) {
      UndirectedGraphNode* current =  Q.front();
      UndirectedGraphNode* clonedCurrent = M[current];
      for (int i = 0; i < current->neighbors.size(); ++i) {
        UndirectedGraphNode* neighbor = current->neighbors[i]; 
        UndirectedGraphNode* clonedNeighbor = NULL;
        if (!M.count(neighbor)) {
          clonedNeighbor = initNodeFrom(neighbor, M, Q);
        } else {
          clonedNeighbor = M[neighbor];
        }
        connect(clonedCurrent, clonedNeighbor);
      }
      Q.pop();
    }
    return ret;
  }
};