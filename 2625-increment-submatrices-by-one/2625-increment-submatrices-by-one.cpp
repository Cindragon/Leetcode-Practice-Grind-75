class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        for(const auto&q:queries){
            pair<int, int> p1={q[0], q[1]};
            pair<int, int> p2={q[2], q[3]};
            for(int i=p1.first;i<=p2.first;++i){
                for(int j=p1.second;j<=p2.second;j++){
                    matrix[i][j]++;
                }
            }
        }
        return matrix;
    }
};