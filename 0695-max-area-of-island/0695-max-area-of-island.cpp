class Solution {
private:
    int m;
    int n;
    vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int dfs(int i, int j, vector<vector<int>>& grid){
        if(i<0||i>=m||j<0||j>=n||grid[i][j]!=1) return 0;
        grid[i][j]=2;
        int ans=1;
        for(const auto&d:dir){
            ans+=dfs(i+d.first, j+d.second, grid);
        }
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()||grid[0].empty())   return 0;
        m=grid.size();
        n=grid[0].size();
        int area=0, maxArea=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    area=dfs(i, j, grid);
                    maxArea=max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};