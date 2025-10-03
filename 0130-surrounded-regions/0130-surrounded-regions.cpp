class Solution {
private:
    int m, n;
    vector<int> dir{0, 1, 0, -1, 0};
    void bfs(vector<vector<char>>& board, int i, int j){
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]!='O')   return;
        queue<pair<int, int>> q;
        q.push({i, j});
        board[i][j]='#';
        while(!q.empty()){
            auto [x, y]=q.front();
            q.pop();
            for(int k=0;k<4;++k){
                int nx=x+dir[k];
                int ny=y+dir[k+1];
                if(nx>=0 && nx<m && ny>=0 && ny<n && board[nx][ny]=='O'){
                    board[nx][ny] = '#';
                    q.push({nx, ny});
                }
            }
        }

    }
public:
    void solve(vector<vector<char>>& board) {
        m=board.size();
        n=board[0].size();
        for(int i=0;i<m;++i){
            if(board[i][0]=='O')    bfs(board, i, 0);
            if(board[i][n-1]=='O')  bfs(board, i, n-1);
        }
        for(int j=0;j<n;++j){
            if(board[0][j]=='O')    bfs(board, 0, j);
            if(board[m-1][j]=='O')  bfs(board, m-1, j);
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]=='O')    board[i][j]='X';
                else if(board[i][j]=='#')   board[i][j]='O';
            }
        }
    }
};

/*
用 BFS 的方式來解題也是一樣
1. 由於只有在邊界上的 O 不會被覆蓋，因此先從邊界開始做 bfs，如果遇到 O 的話就標記成#
表示是在邊界上的領域，不會變成 X
2. 接下來再一次遍歷 board，此時只要遇到是 O 的就變成 X，如果遇到 # 就變回 O
*/

/*
class Solution {
private:
    int m, n;
    vector<int> dir{1, 0, -1, 0, 1};
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]!='O')  return;
        board[i][j]='#';
        for(int k=0;k<4;k++){
            int nx=i+dir[k];
            int ny=j+dir[k+1];
            dfs(board, nx, ny);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        m=board.size();
        n=board[0].size();

        for(int i=0;i<m;++i){
            dfs(board, i, 0);
            dfs(board, i, n-1);
        }
        for(int j=0;j<n;++j){
            dfs(board, 0, j);
            dfs(board, m-1, j);
        }    
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
};


用 DFS 的方式來解題
1. 由於只有在邊界上的 O 不會被覆蓋，因此先從邊界開始做 dfs，如果遇到 O 的話就標記成#
表示是在邊界上的領域，不會變成 X
2. 接下來再一次遍歷board，此時只要遇到是 O 的就變成 X，如果遇到 # 就變回 O
*/