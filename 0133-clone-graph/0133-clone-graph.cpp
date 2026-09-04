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
private:
    void dfs(Node* node, unordered_map<Node*, Node*>& mp){
        if(!node||mp.count(node))    return;
        mp[node]=new Node(node->val);
        for(const auto&next:node->neighbors){
            dfs(next, mp);
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node)   return nullptr;
        unordered_map<Node*, Node*> mp;
        dfs(node, mp);
        for(const auto&[origin, copy]:mp){
            for(const auto&next:origin->neighbors){
                copy->neighbors.push_back(mp[next]);
            }
        }
        return mp[node];
    }
};

/*
用 DFS 的概念來解題
首先要有一個 map 來儲存原圖的所有節點，把所有節點儲存之後，再將節點之間的關聯進行連接。
dfs 函式：
    在 node 為空或是已經加入的節點，直接return
    若是還沒有加入，就將這個節點跟連接的節點加入map，接著繼續遍歷其鄰居，直到所有的點都加到 map 中
接著遍歷整個 map [origin, copy]，並且遍歷原本的origin 節點的鄰居，把這些鄰居一樣複製到copy的鄰居
最後回傳整個新圖的入口(其中便包含了所有複製的節點鄰居)
*/