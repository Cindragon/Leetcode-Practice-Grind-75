class Solution {
private:
    int m, n;
    vector<int> dir={1,0,-1,0,1};
    bool dfs(int i, int j, int startIndex, vector<vector<char>>& board, string& word){
        if(i<0 || i>=m || j<0 || j>=n) return false;
        if(board[i][j]!=word[startIndex])   return false;    
        if(startIndex==word.size()-1)   return true;
        char temp=board[i][j];
        board[i][j]='#';
        for(int k=0;k<4;k++){
            int ni = i + dir[k];
            int nj = j + dir[k+1];
            if(dfs(ni, nj, startIndex+1, board, word)){
                board[i][j]=temp;
                return true;
            }
        }
        board[i][j]=temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(i, j, 0, board, word)) return true;
            }
        }
        return false;
    }
};

/*
這可以用 DFS 加上 回溯算法的方式來解題
DFS 的過程中有三個終止條件：
    超出邊界回傳 false、字符不同回傳 false、
    startIndex==word.size()-1 回傳 true(代表找到字了)
在回溯時，將原本的字符儲存，並且用 # 代替已找過的字
在主函式中，從 board[0][0] 開始遍歷，若是找到 word 回傳 true 沒找到回傳false
*/