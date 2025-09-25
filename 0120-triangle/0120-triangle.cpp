class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> dp(n, INT_MAX);
        dp[0]=triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=i;j>=0;j--){
                if(j==0){
                    dp[j]=dp[j]+triangle[i][j]; //左邊界
                }
                else if(i==j){
                    dp[j]=dp[j-1]+triangle[i][j];   //右邊界
                }
                else{
                    dp[j]=min(dp[j], dp[j-1])+triangle[i][j];
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans, dp[i]);
        }
        return ans;
    }
};

/*
用動態規劃的方式來處理這題
1. dp 陣列定義：表示到達當前層第 j 個元素的最小路徑和為 dp[j]
2. 遞推公式：(i只能走左下或是右下)
    左邊界(j == 0)：dp[j]=dp[j]+triangle[i][j]
    右邊界(j == i)：dp[j]=dp[j-1]+traingle[i][j]
    中間：(0<j<i)dp[j]=min(dp[j], dp[j-1])+triangle[i][j]，要考慮左上和正上兩條路徑的最小值
3. 初始化：dp[0]=triangle[0][0](第一層只有一個數)
4. 遍歷順序：   
    - 層數 i：從上到下
    - 層內 j：從右到左，避免覆蓋上一層還沒使用的數值
5. 最後遍歷整個三角形之後，找到最小路徑和
*/