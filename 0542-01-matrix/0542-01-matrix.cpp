class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i, j});
                }
                else{
                    mat[i][j]=INT_MAX;
                }
            }
        }
        while(!q.empty()){
            pair<int, int> pos=q.front();
            q.pop();
            int row=pos.first;
            int col=pos.second;
            for(const auto&d:dirs){
                int newRow=row+d.first;
                int newCol=col+d.second;
                if(newRow>=0 && newRow<m && newCol>=0 && newCol<n 
                && mat[newRow][newCol]>mat[row][col]+1){
                    mat[newRow][newCol]=mat[row][col]+1;
                    q.push({newRow, newCol});
                }
            }
        }
        return mat;
    }
};
/*
使用 BFS 的方式來遍歷整個陣列
一樣先求出 mat 陣列大小以及 dirs 四個方向，並且使用 queue 來儲存 0 的座標
接著遍歷整個 mat，將位置是 0 的座標放進佇列中，其他非 0 位置則初始化為 INT_MAX(後面再來更新)
接著在queue不為空的情況下，逐一取出各個座標，並且遍歷四個方向(用 {row, col} 跟 {newRow, newCol} 來表示)
在陣列範圍的情況下以及 mat[newRow][newCol]>mat[row][col]+1(INT_MAX> 0+1 ) 的條件下
將新座標的值進行變更，最後再直接回傳更改過後的陣列就好。
*/