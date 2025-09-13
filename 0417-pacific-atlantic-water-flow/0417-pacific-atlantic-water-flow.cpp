class Solution {
private:
    int m;
    int n;
    vector<int> dir{0, 1, 0, -1, 0};
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>&visited){
        if(i<0||i>=m||j<0||j>=n) return;
        if(visited[i][j]) return;
        visited[i][j] = true;
        for(int d=0;d<4;d++){
            int nx=i+dir[d];
            int ny=j+dir[d+1];
            if(nx>=0 && nx<m && ny>=0 && ny<n 
            && heights[i][j]<=heights[nx][ny]){ //新的格子高度不低於原本的格子
                dfs(nx, ny, heights, visited);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size();
        n=heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for(int i=0;i<m;i++) dfs(i, 0, heights, pacific);
        for(int j=0;j<n;j++) dfs(0, j, heights, pacific);

        for(int i=0;i<m;i++) dfs(i, n-1, heights, atlantic);
        for(int j=0;j<n;j++) dfs(m-1, j, heights, atlantic);
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j]&&atlantic[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};

/*
用兩張陣列圖來去做太平洋跟大西洋的狀態，只要找到交集都是 true 的就是可以流到兩邊海洋的格子
因此兩個陣列以bool為值 (初始值為false)
接著用 DFS 的方式，從左邊界跟上邊界更新太平洋陣列，接著從右邊界跟左邊界更新大西洋陣列
DFS 的函式：
    1. 若超出邊界，直接 return
    2. 若該座標 visited[i][j]=true，直接 return(表示此格子能流到海洋，不需要重複搜索)
    ，而不符合條件的格子不會被DFS訪問，也就不會標記。
    3. 先將這個座標設為 true，接著遍歷四個方向，一但這個格子在範圍內，
    且新的格子高度不低於原本的格子，則繼續對該格子進行 DFS，直到無法再擴展為止
最後再遍歷一次所有格子，將交集都是 true 的座標儲存並回傳
*/
