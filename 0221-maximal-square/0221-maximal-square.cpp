class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans=0;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(matrix[i][j]=='1'){
                    if(i==m-1||j==n-1){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=1+min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]});
                    }
                    ans=max(ans, dp[i][j]);
                }
            }
        }
        return ans*ans;
    }
};

/*
用 dp 算法解決本題
dp 數組定義：表示「以 (i, j) 為左上角」能形成的最大正方形的邊長
初始化：dp 數組初始化為 0 (從 0 開始加)，
當 matrix[i][j] == '1' 且在最後一行或最後一列時，dp[i][j] = 1
遞推公式：dp[i][j]=1+min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]});
取右方、下方、右下方的最小值，再加 1
遍歷順序：從右下角開始由下往上，由右至左，並且更新邊界長度，最後回傳ans相乘
*/