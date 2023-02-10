/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* c) {
        if(c == nullptr) return nullptr;
        
        unordered_map<Node*, Node*> oldToNewNodes;

        // BFS
        queue<Node*> q;
        unordered_set<Node*> visited;

        q.push(c);
        visited.insert(c);

        while(!q.empty()){
            Node* currentNode = q.front();
            q.pop();

            // create a new node
            Node* newNode = new Node(currentNode->val);
            oldToNewNodes[currentNode] = newNode;

            for(auto neighbour: currentNode->neighbors){
                if(!visited.count(neighbour)){
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }


        // link the nodes
        auto it = oldToNewNodes.begin();
        while(it != oldToNewNodes.end()){
            for(auto neighbour: it->first->neighbors){
                it->second->neighbors.push_back(oldToNewNodes[neighbour]);
            }
            it++;
        }

        return oldToNewNodes[c];
    }
};