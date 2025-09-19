class Solution {
private:
    void dfs(string airport, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& graph, vector<string>& route){
        auto& dests=graph[airport];
        while(!dests.empty()){
            string next=dests.top();
            dests.pop();
            dfs(next, graph, route);
        }
        route.push_back(airport);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for(const auto&t:tickets){
            graph[t[0]].push(t[1]);
        }
        vector<string> route;
        dfs("JFK", graph, route);
        reverse(route.begin(), route.end());
        return route;
    }
};