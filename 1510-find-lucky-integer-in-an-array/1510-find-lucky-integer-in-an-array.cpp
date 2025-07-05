class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(const auto&i:arr){
            mp[i]++;
        }
        int ans=-1;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->first==it->second){
                ans=max(ans, it->first);
            }
        }
        return ans;
    }
};