class Solution {
public:
    int m, n;
    vector<pair<int, int>> dir={{1,0}, {0, 1}, {-1, 0}, {0, -1}};
    int dfs(int i, int j, vector<vector<int>>&matrix, vector<vector<int>>&dp){
        if(dp[i][j]!=0) return dp[i][j];
        int res=1;
        for(const auto&d:dir){
            int x=i+d.first;
            int y=j+d.second;
            if(x>=0 && x<m && y>=0 && y<n && matrix[i][j]<matrix[x][y]){
                res=max(res, 1+dfs(x, y, matrix, dp));
            }
        }
        dp[i][j]=res;
        return res;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans, dfs(i, j, matrix, dp));
                cout<<dp[i][j];
            }
            cout<<endl;
        }
        return ans;
    }
};

/*
使用動規五部曲的方式來解題
1. dp 數組定義：從 (i, j) 出發的最長遞增路徑長度為 dp[i][j]
2. 確定遞推公式：要用 dfs 的方式來遍歷每一格走的方向是否為遞增路徑，
因此透過 dir 陣列，對於每個方向 (上下左右)，若 matrix[x][y] > matrix[i][j]，則更新最長路徑的長度。
初始值 res 為 1 (包含自己)
res=max(res, 1+dfs(m, n, x, y, matrix, dp));
3. 初始化：設立一個 m*n 大小的陣列，並且將值初始化為0
4. 遍歷順序：透過 dfs 加上記憶化的概念，遍歷整個矩陣，對每個格子呼叫 dfs，並且用 ans 來更新最長路徑的長度，最後回傳最大值。
5. 印出 dp 數組 (非必要)：用來檢查自己的邏輯是否正確
*/