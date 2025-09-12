class Solution {
private:
    int m;
    int n;
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(i<0||i>=m||j<0||j>=n||grid[i][j]!='1')   return;
        grid[i][j]='2';
        dfs(i-1, j, grid);
        dfs(i+1, j, grid);
        dfs(i, j-1, grid);
        dfs(i, j+1, grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()||grid[0].empty())  return 0;
        m=grid.size();
        n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};

/*
透過 dfs 的方式來確認島嶼的範圍跟數量
dfs 函式為，從上下左右四個方向遍歷，如果超出邊界，或是遇到不等於 1 (代表碰到水或是走到算過的島嶼面積)，就return
若是沒有就將 grid[i][j] 改成 2 (代表走過了)
而在遍歷時，從上到下，從左到右，若是遇到 gird[i][j] == 1，代表遇到一座新的島嶼
那就用 dfs 的方式來確認島嶼面積，並且將 ans ++，最後回傳
*/