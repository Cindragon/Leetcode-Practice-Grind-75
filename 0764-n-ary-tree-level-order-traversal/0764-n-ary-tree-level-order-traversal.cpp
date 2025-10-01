/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        if(root!=NULL)  q.push(root);
        int size;
        while(!q.empty()){
            size=q.size();
            vector<int> v;
            while(size--){
                Node* curr=q.front();
                q.pop();
                v.push_back(curr->val);
                //把 curr 所有的 children 放進 q
                for (Node* child : curr->children) {
                    if (child) q.push(child);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};