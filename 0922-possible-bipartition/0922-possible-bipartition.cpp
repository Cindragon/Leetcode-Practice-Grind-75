class Solution {
private:
    vector<int> father;
    int find(int u){    //路徑壓縮
        if(u==father[u])    return u;
        father[u]=find(father[u]);
        return father[u];
        /*
        if(u==father[u])    return u;
        int father=find(father[u]);
        return father;
        */
    }
    void join(int a, int b){
        a=find(a);
        b=find(b);
        if(a==b)    return;
        father[a]=b;    //father[find(a)]=find(b)
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);
        for(const auto&d:dislikes){
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }
        // graph[1]={2, 3}、graph[2]={1, 4};
        father.resize(n+1);
        for(int i=1;i<=n;++i)   father[i]=i;
        for(int i=1;i<=n;++i){
            if(graph[i].empty())    continue;
            int firstEnemy=graph[i][0];
            for(const auto&e:graph[i]){
                join(firstEnemy, e);
                if(find(i)==find(e))    return false;//如果發現被分到同一組，return false
            }
        }
        return true;
    }
};
/*
我們需要用 graph 來儲存互相不喜歡的關係(無向圖)
遍歷 dislike 的組合，如果 a 不喜歡 b ，那麼等同 b 不喜歡 a(不然有可能被分在同一組)
接著將 father 做 resize，並且先將各節點的父節點設為自己
接著遍歷 graph 圖：
    先找到 i 的 firstEnemy，並且繼續遍歷 i 的其他敵人(e)並且進行 join(分到同一組)
    如果發現 i 跟 e 的 father 相等，表示 i 和 e 被歸到同一集合裡（同一陣營），那就 return false
*/

