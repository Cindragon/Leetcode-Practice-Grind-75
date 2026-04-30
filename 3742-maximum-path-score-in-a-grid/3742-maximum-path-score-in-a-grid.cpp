class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector dp(m, vector(n, vector<int>(k+1, -1)));
        dp[0][0][0]=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                for(int c=0;c<=k;++c){
                    if(dp[i][j][c]==-1) continue;

                    if(i+1<m){
                        int nc=c+(grid[i+1][j]>0);
                        if(nc<=k){
                            dp[i+1][j][nc]=max(dp[i+1][j][nc], dp[i][j][c]+grid[i+1][j]);
                        }
                    }

                    if(j+1<n){
                        int nc=c+(grid[i][j+1]>0);
                        if(nc<=k){
                            dp[i][j+1][nc]=max(dp[i][j+1][nc], dp[i][j][c]+grid[i][j+1]);
                        }
                    }
                }
            }
        }
        return *max_element(dp[m-1][n-1].begin(), dp[m-1][n-1].end());
    }
};

/*
dp 數組定義：在限制走k次之前，到達grid[i][j]位置的最大值為dp[i][j]
初始化：全部都先初始化為 -1，dp[0][0][0]=0，一開始初始值為 0(還沒開始走)
遞推公式：
    if(dp[i][j][c]==-1) continue;代表這邊沒有路了
    在範圍內，如果步數還夠(nc<=k)，那就進行比較最大值
遍歷順序：從gird(0, 0)開始走
最後回傳最大元素即可
*/