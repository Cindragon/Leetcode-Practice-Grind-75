class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int up=m, bottom=-1, left=n, right=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    up=min(i, up);
                    bottom=max(i, bottom);
                    left=min(j, left);
                    right=max(j, right);
                }
            }
        }
        if(bottom==-1)  return 0;   //代表沒有任何1
        int height=bottom-up+1;
        int width=right-left+1;
        return height*width;

    }
};

/*
使用迴圈的方式來找到最小的覆蓋面積
用四個變數 up bottom left right 儲存矩形的四邊位置
    - up    : 紀錄出現 1 的最上方 row (初始化為 m，遇到 1 就取更小的 row)
    - bottom: 紀錄出現 1 的最下方 row (初始化為 -1，遇到 1 就取更大的 row)
    - left  : 紀錄出現 1 的最左方 col (初始化為 n，遇到 1 就取更小的 col)
    - right : 紀錄出現 1 的最右方 col (初始化為 -1，遇到 1 就取更大的 col)
接下來透過迴圈來掌握面積，由左至右，由上往下
遍歷 grid 時，當 grid[i][j] == 1，就更新四個邊界。
最後算完之後計算面積回傳
*/
