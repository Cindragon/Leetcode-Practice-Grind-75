class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(const auto&r:relations){
            int a=r[0]-1, b=r[1]-1;
            adj[a].push_back(b);
            indegree[b]++;
        }
        queue<int> q;
        vector<int> dp(n, 0);
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                dp[i]=time[i];   //第 i 堂課最早完成的時間
                q.push(i);
            }
        }
        int ans=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            ans=max(ans, dp[curr]);
            for(int next:adj[curr]){
                dp[next]=max(dp[curr]+time[next], dp[next]);
                if(--indegree[next]==0){
                    q.push(next);
                }
            }
        }
        return ans;
    }
};

/*
我們要找完成所有課程所需的最短總時間。
由於課程之間有先修依賴關係 (a → b)，這是一個「有向無環圖 (DAG)」。

一樣要建立入度圖跟鄰接表
1. 一個二維陣列 adj (鄰接表)，adj[i] 代表從課程 i 出發可以修的後續課程(變為 0-index)
透過indegree[i] 記錄每門課的入度（還有多少先修課沒修）。
2. 接著透過 queue 將 入度為0的課程加入，並且用 dp 陣列來儲存課堂 i 最少需要多少時間
3. - 每次從 queue 取出一門課 cur，表示這門課的所有先修課都已完成
   - 對於每個後續課程 next：
        dp[next] = max(dp[next], dp[cur] + time[next])
     代表完成 next 至少要等到 cur 完成後再加上自己的時間
   - 每更新一次 indegree[next]--
     若 indegree[next] 變成 0，代表所有先修課都完成，加入 queue
*/