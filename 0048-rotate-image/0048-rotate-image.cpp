class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0;i<n;++i){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

/*
將除了對角以外的元素進行互換
接下來再將每一行進行反轉就好
*/