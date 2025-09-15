class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(const auto&p:prerequisites){
            int a=p[0], b=p[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        for(int i=0;i<n;++i){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int ans=0;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            ans++;
            for(int a:adj[t]){
                indegree[a]--;
                if(indegree[a]==0){
                    q.push(a);
                }
            }
        }
        return ans==n;
    }
};

/*
採用 BFS 的方式來解題(Kahn（BFS，入度法）)，用到拓撲排序的概念。
1. 首先用
    一個二維陣列 adj (鄰接表)，adj[i] 代表從課程 i 出發可以修的後續課程， 
    n 代表課程總數
    透過indegree[i] 記錄每門課的入度（還有多少先修課沒修）。

2. 接下來遍歷 prerequisite 陣列，將每個課程所需要的先修課程記錄下來並且計算入度
    對每個 [a,b]，表示「修 a 前必須先修 b」
    在圖中加入邊 b -> a

3. 透過 queue 陣列將入度為 0 的課程 push 進 queue 中（代表可以第一時間先修的課程）

4. 用 ans 記錄課堂數，在 queue 不為空的情況下，將裡面的課堂代號 t 拿出來，並且 ans++

5. BFS 遍歷：
   - 從 queue 拿出課程 t，ans++
   - 遍歷 t 的後續課程 a：
       - 將 indegree[a]--（表示已完成一個先修課）
       - 如果 indegree[a] == 0，代表 a 現在可以修了，放入 queue

6. - 如果 ans == n，表示所有課程都能修完（無環）
   - 否則有循環，無法完成所有課程
*/