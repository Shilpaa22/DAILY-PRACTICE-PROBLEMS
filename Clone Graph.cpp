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
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        unordered_map<Node*,Node*> m;
        Node* ans = new Node(node->val,{});
        m[node]=ans;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* currNode=q.front();
            q.pop();
            vector<Node*> neigh = currNode->neighbors;
            for(auto x:neigh){
                if(m.find(x)==m.end()){
                    m[x] = new Node(x->val,{});
                    q.push(x);
                }
                m[currNode]->neighbors.push_back(m[x]);
            }
        }
        return ans;
    }
};