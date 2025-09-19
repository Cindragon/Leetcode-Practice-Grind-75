class Solution {
private:
    unordered_map<string, vector<pair<string, double>>> graph;
    double dfs(string curr, string target, unordered_set<string>& visited, double val){
        if(curr==target)    return val; // 找到目標，回傳累積乘積
        visited.insert(curr);   // 標記已拜訪
        for(const auto&[next, weight]:graph[curr]){
            if(!visited.count(next)){   // 沒走過才進行遞迴
                double res=dfs(next, target, visited, val*weight);
                if(res!=-1.0)   return res;
            }
        }
        return -1.0;    // 無法找到路徑
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0;i<equations.size();i++){
            string a=equations[i][0], b=equations[i][1];
            double val=values[i];
            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0/val});
        }
        vector<double> ans;
        for(const auto&q:queries){
            string start=q[0], end=q[1];
            if(!graph.count(start)||!graph.count(end)){
                ans.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            ans.push_back(dfs(start, end, visited, 1.0));
        }
        return ans;
    }
};

/*
這題可以用 DFS 或是 BFS 的方式解決
首先需要一張 map 來儲存各個節點連結到其他節點的權重圖，
將每個方程式建立成圖：節點為變數，邊的權重為除法值
1. 遍歷 equations，儲存各節點到另一個節點的權重值(兩邊都要)
2. 建立 ans 陣列，並且開始遍歷 queries 陣列：
    - 遇到沒有在 graph 中的值直接回傳 -1.0
    - 遇到有在 graph 中的值，設定一個 visited set(用來查看路徑是否走過，避免死循環)
    用 DFS 來找到值，最後 push_back 進 ans
DFS 函式：傳入 curr, target , visited 跟 val
    - 若 curr==target，// 找到目標，回傳累積乘積
    - 接著將 curr 加入 visited(代表走過這條路)，遍歷 graph 中 curr 這個節點的所有點以及權重
    - 以 [next, weight] 的組合進行遍歷，在 next 節點不在 visited 中時，
      透過 DFS 函式，遍歷鄰居，累積乘積 val * weight，持續更新 val 的值，
      如果不是 -1，那就回傳 res
    - 最後若是無法找到路徑，直接回傳 -1.0
*/