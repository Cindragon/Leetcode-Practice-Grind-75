class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        // minDist[v]: v 點到目前已建立的 MST 的最小距離
        vector<int> minDist(n, INT_MAX);
        // visited[v]: 是否已將 v 納入 MST
        vector<bool> visited(n, false);

        auto dist=[&](int i, int j){
            return abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
        };
        // 最小優先隊列: {目前距離, 點編號}
        // 用來挑選下一個成本最低的點加入 MST
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0}); //從 points[0] 開始，cost 為 0
        minDist[0]=0;
        int ans=0;
        while(!pq.empty()){
            auto [cost, u]=pq.top();
            pq.pop();
            if(visited[u])  continue;
            visited[u]=true; //拜訪過這個點
            ans+=cost;
            for(int v=0;v<n;++v){ //接下來從 point[1] 開始遍歷
                if(!visited[v]){
                    int d=dist(u, v);
                     // 如果透過 u 連到 v 更便宜，更新
                    if(d<minDist[v]){
                        minDist[v]=d;
                        pq.push({d, v});
                    }
                }
            }
        }
        return ans;
    }
};

/*
Prim’s Algorithm MST 實作 (使用 priority_queue)

核心概念:
1. 每次選當下可以加入 MST 的最小距離點
2. minDist 記錄每個點距離既有 MST 的最短連結成本
3. visited 用來避免重複加入
4. 用 priority_queue 動態挑選最小邊
*/