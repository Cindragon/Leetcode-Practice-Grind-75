class Solution {
public:
    bool backtracking(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){
                        if(isValid(i, j, k, board)){
                            board[i][j]=k;
                            if(backtracking(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;   //9個數都試完了，都沒辦法，就return false
                }
            }
        }
        return true;    //全部的棋盤都填滿了，找到一個解，return true
    }
    bool isValid(int x, int y, char k, vector<vector<char>>& board){
        //同一行裡面有沒有相同數字
        for(int i=0;i<9;i++){
            if(board[i][y]==k) return false;
        }
        //同一列裡有沒有相同數字
        for(int j=0;j<9;j++){
            if(board[x][j]==k) return false;
        }
        //周遭的九宮格有沒有相同的數字
        int startX=(x/3)*3;
        int startY=(y/3)*3;
        for(int i=startX;i<startX+3;i++){
            for(int j=startY;j<startY+3;j++){
                if(board[i][j]==k) return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};

/*
數獨問題同樣可以用回溯算法解決
比較特別的是回傳值是 bool 型態，因為只要有找到一個解就可以結束遞迴了
傳入參數為 board 棋盤(參考值傳入)
要用到兩層的 for 迴圈來遍歷整個棋盤
如果找到空格，用 for 迴圈枚舉1~9的數字
用isValid函數來判斷這個數字在這個位置(board[i][j])是否合法
如果可以就放入這個值，接著持續遞迴，最後回溯。
isValid函數則是要檢查同行/同列/九宮格中，有沒有出現這個數
最後回傳回溯函數的結果，`board` 就是已經被修改過、填入正確數字的解。
*/