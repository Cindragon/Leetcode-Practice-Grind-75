class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adj(n);
        vector<int> outDegree(n, 0);
        for(int i=0;i<n;++i){
            outDegree[i]=graph[i].size();   // i 的出度 = i 指出去的邊數
            for(const auto&v:graph[i]){
                adj[v].push_back(i);    //建立反向圖 v <- i
            }
        }
        queue<int> q;
        for(int i=0;i<n;++i){
            if(outDegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(const auto&v:adj[node]){
                outDegree[v]--; // 移除一條指向 node 的出邊
                if(outDegree[v]==0){ // 如果出度變 0 → 安全
                    q.push(v);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

/*
這題跟跟 207 還有 210 很像，都是用到拓撲排序的概念。
前面兩題用到的是入度法，而這題用到的則是出度法(反向圖)
我們的 adj[v] 要儲存的是有幾個點指到 node v，outDegree[v] 則代表 node v 指了幾條線出去(出度)
接下來我們一樣開始儲存這個 graph(反向)
1. 遍歷 graph 陣列，建立整個反向圖，並且記錄各個點的出度
2. 接著一樣用 queue 來儲存出度為 0 的點(代表這些點為安全節點)
3. 接著在 q 不為空的情況下，先儲存 q.front()，接著開始遍歷這個 node 在 adj 裡指向 node 的點(v)
outDegree[v]--(出度剪掉一個邊)，當出度為 0 的時候，節點 v 就變安全節點，一樣 push 到 q 裡面
4. 最後回傳排序過後的 ans 陣列
*/