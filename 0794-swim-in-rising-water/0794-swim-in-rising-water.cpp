class Solution {
private:
    int m, n;
    vector<int> dir{1, 0, -1, 0, 1};
    bool bfs(vector<vector<int>>& grid, int value){
        if(grid[0][0]>value)    return false;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>>q;
        q.push({0, 0});
        visited[0][0]=true;
        while(!q.empty()){
            auto [x, y]=q.front();
            q.pop();
            if(x==m-1 && y==n-1)    return true;
            for(int k=0;k<4;k++){
                int nx=x+dir[k];
                int ny=y+dir[k+1];
                if(nx<0 || nx>=m || ny<0 || ny>=n)  continue;
                if(!visited[nx][ny] && grid[nx][ny]<=value){
                    visited[nx][ny]=true;
                    q.push({nx, ny});
                }
            }
        }
        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int left=grid[0][0], right=m*n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(bfs(grid, mid)){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};

/*
這題可以用 DFS 或是 BFS 的方式加上二元搜索法來解決
首先找到 left=gird[0][0] 起點的數值，right 為陣列中的最大值
接著在 left<right
*/
