class Solution {
private:
    void dfs(int i, vector<string>&strs, vector<bool>&visited){
        visited[i]=true;
        for(int j=0;j<strs.size();++j){
            if(visited[j])   continue;
            if(isSmilar(strs[i], strs[j])){
                dfs(j, strs, visited);
            }
        }
    }
    bool isSmilar(const string &a, const string& b){
        int count=0;
        for(int i=0;i<a.size();++i){
            if(a[i]!=b[i]){
                count++;
            }
        }
        return (count==2 || count==0);
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int ans=0, n=strs.size();
        vector<bool> visited(n, false);
        for(int i=0;i<n;++i){
            if(visited[i])   continue;
            ans++;
            dfs(i, strs, visited);
        }
        return ans;
    }
};

/*
這題用到了dfs的做法，將各個單字進行比較
從第一個單字開始跟其他單字做比較，並且如果在 visited 中已經被遍歷過了，那就直接跳過
ans++(代表目前有一個組別)，並且開始進行dfs
在 dfs 函式中，先將遍歷到的單字設為 true，並且開始與其他單字進行比較，若是為 ture跳過，
如果在 isSmilar 中有兩個不同的字母或是沒有不同的字母代表相似
最後回傳計算後的ans
*/