class Solution {
public:
    class mycomparison{
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs){
            return lhs.second>rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(const auto&n:nums){
            mp[n]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        for(unordered_map<int, int>::iterator it=mp.begin();it!=mp.end();it++){
            pri_que.push(*it);
            if(pri_que.size()>k){
                pri_que.pop();
            }
        }
        vector<int> ans(k);
        for(int i=k-1;i>=0;i--){
            ans[i]=pri_que.top().first;
            pri_que.pop();
        }
    return ans;
    }
};