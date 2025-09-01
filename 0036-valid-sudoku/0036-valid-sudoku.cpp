class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row=0;row<9;row++){
            unordered_set<char> seen;
            for(int i=0;i<9;i++){
                if(board[row][i]=='.')  continue;
                if(seen.count(board[row][i]))   return false;
                seen.insert(board[row][i]);
            }
        }
        for(int col=0;col<9;col++){
            unordered_set<char> seen;
            for(int i=0;i<9;i++){
                if(board[i][col]=='.')  continue;
                if(seen.count(board[i][col]))   return false;
                seen.insert(board[i][col]);
            }
        }
        for(int s=0;s<9;s++){
            unordered_set<char> seen;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    int row=(s/3)*3+i;
                    int col=(s%3)*3+j;
                    if(board[row][col]=='.')    continue;
                    if(seen.count(board[row][col])) return false;
                    seen.insert(board[row][col]);
                }
            }
        }
        return true;
    }
};

/*
使用暴力解的解法，驗證每一行每一列以及每個正方形裡面是否有重複的 1~9
用 set 的方式來找是否有重複
如果有 return false
最後都沒有找到重複的數字就 return true
*/