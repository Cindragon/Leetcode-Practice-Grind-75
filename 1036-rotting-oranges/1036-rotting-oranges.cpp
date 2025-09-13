class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int, int>> q;
        int freshOrange=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                }
                if(grid[i][j]==1){
                    freshOrange++;
                }
            }
        }
        if(freshOrange==0)  return 0;
        if(q.empty())   return -1;
        int minutes=-1;
        vector<pair<int, int>>dirs ={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            int num=q.size();
            while(num--){
                auto [x, y]=q.front();
                q.pop();
                for(const auto&d:dirs){
                    int i=x+d.first;
                    int j=y+d.second;
                    if(i>=0 && i<m && j>=0 && j<n && grid[i][j]==1){
                        grid[i][j]=2;
                        freshOrange--;
                        q.push({i, j});
                    }
                }
            }
            minutes++;
        }
        if(freshOrange==0){
            return minutes;
        }
        return -1;
    }
};

/*
這題一樣用 BFS 的方式來解決，
1. 首先求出陣列大小並且列出四個方向跟 queue 來儲存壞掉橘子的座標

2. 接著遍歷整個陣列，儲存壞橘子座標跟好橘子的數量

3. 如果沒有好橘子，回傳 0 ；如果 queue 為空，一樣回傳 0 (代表不需要操作)

4. BFS 遍歷
   - 每一輪 BFS 處理 queue 中的所有元素，這代表「同一分鐘內會腐爛的橘子」。
   - 用 num = q.size() 記錄這一層橘子數量。
    在 num-- 的情況下，將其中一個壞橘子的座標取出，並且用其座標遍歷四個方向
    只要這個座標在上下左右的位置有一顆好橘子，那麼就將他變成壞橘子
    並且好橘子數量減一之後，再將他的位置 push 進 queue(可能感染下一顆橘子)
    而每過一輪的 BFS，時間就要 +1 分鐘(從 -1 開始算，因為第一層 queue 中的橘子本來就是壞的，不算時間)

最後若是所有橘子都變成壞橘子就回傳分鐘數，若是還有好橘子就回傳 -1 
*/