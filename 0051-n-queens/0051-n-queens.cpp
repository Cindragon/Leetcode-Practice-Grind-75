class Solution {
public:
    vector<vector<string>> res;
    void backtracking(vector<string>& board, int n, int y){
        if(y==n){
            res.push_back(board);
            return;
        }
        for(int x=0;x<n;x++){
            if(isValid(board, x, y, n)){
                board[x][y]='Q';
                backtracking(board, n, y+1);
                board[x][y]='.';               
            }
        }
        return;
    }
    bool isValid(vector<string>& board, int x, int y, int n){ //檢查同行跟對角線有沒有Q
        for(int i=0;i<y;i++){   // 檢查左方是否有皇后（同一列左邊）
            if(board[x][i]=='Q') return false;
        }
        for(int i=x-1, j=y-1; i>=0&&j>=0;i--,j--){  // 檢查左上 ↖ 45 度角
            if(board[i][j]=='Q') return false;
        }
        for(int i=x+1, j=y-1;i<n&&j>=0;i++, j--){   // 檢查右上 ↗ 135 度角
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        vector<string> board(n, string(n, '.'));
        backtracking(board, n, 0);
        return res;
    }
};

/*
比想像中還要不複雜，一樣是使用回溯算法來解題
從第一列開始，將Q放進棋盤，並且使用isValid函數來檢查這個位置是否合法
傳入參數：棋盤、棋盤大小(n)、row(y)
終止條件：y==棋盤大小，代表可以將棋盤結果傳入res中
單層遞迴邏輯：
    從第一行開始進行迴圈，並且使用isValid函數
    如果這個位置(board[x][y])可以放皇后，那麼就將皇后放在這邊
    然後繼續遞迴(下一列)，並且也要進行回溯
isValid函數：檢查這個位置是不是可以放皇后
因為我們是一列一列地放皇后（每列只放一個），所以只需檢查左邊與左上、右上是否已經有皇后，
右方與下方還沒放過所以不用檢查。
最後回傳res
*/