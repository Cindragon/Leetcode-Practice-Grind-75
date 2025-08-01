class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp;
        dp.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int> row;
            vector<int>& preRow = dp[i-1];
            row.push_back(1);
            for(int j=1;j<i;j++){
                row.push_back(preRow[j-1]+preRow[j]);
            }
            row.push_back(1);
            dp.push_back(row);
        }
        return dp;
    }
};

/*
這題一樣可以用動態規劃的方式
dp 數組定義：dp[i][j] 表示第 i 行（從 0 開始）第 j 個元素的數值
遞推公式：除了前後兩個數為1，其他數都是由上面跟左上方的數加起來的
使用 preRow 儲存上一行的結果
dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
初始化：第一個數為 1，每一層遍歷結束時也要在 push_back 一個 1
遍歷順序：以兩層迴圈下去跑
第一層遍歷第幾行，第二層則是遍歷整個陣列的數字
最後將每一層的結果 push_back 進 dp 數組後回傳
*/