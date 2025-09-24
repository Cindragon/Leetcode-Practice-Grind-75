class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp=[](const pair<int, int>&a, const pair<int, int>&b){
            return a.first*a.first+a.second*a.second>b.first*b.first+b.second*b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for(const auto&point:points){
            pair<int, int> p;
            p.first=point[0];
            p.second=point[1];
            pq.push(p);
        }
        vector<vector<int>> ans;
        while(k>0 && !pq.empty()){
            auto point=pq.top();
            pq.pop();
            ans.push_back({point.first, point.second});
            k--;
        }
        return ans;
    }
};