class Solution {
public:
    vector<vector<string>> res;
    void backtracking(vector<string>& chessBoard, int n, int row){
        if(row==n){
            res.push_back(chessBoard);
            return;
        }
        for(int col=0;col<n;col++){
            if(isValid(row, col, chessBoard, n)){
                chessBoard[row][col]='Q';
                backtracking(chessBoard, n, row+1);
                chessBoard[row][col]='.';
            }
        }
        return;
    }
    bool isValid(int row, int col, vector<string>& chessBoard, int n){
        for(int i=0;i<row;i++){
            if(chessBoard[i][col]=='Q') return false;
        }
        for(int i=row-1, j=col-1;i>=0&&j>=0;i--, j--){
            if(chessBoard[i][j]=='Q') return false;
        }
        for(int i=row-1, j=col+1;i>=0&&j<n;i--, j++){
            if(chessBoard[i][j]=='Q') return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        vector<string> chessBoard(n, string(n, '.'));
        backtracking(chessBoard, n, 0);
        return res;
    }
};