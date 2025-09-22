class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans=0, maxFreq=0;
        for(const auto&n:nums){
            mp[n]++;
            maxFreq=max(maxFreq, mp[n]);
        }
        for(auto iter=mp.begin();iter!=mp.end();iter++){
            if(iter->second==maxFreq){
                ans+=iter->second;
            }
        }
        return ans;
    }
};