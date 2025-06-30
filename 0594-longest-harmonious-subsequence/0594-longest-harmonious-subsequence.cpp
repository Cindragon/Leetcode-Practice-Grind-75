class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(const auto&i:nums){
            mp[i]++;
        }
        int maxLen=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            int num=it->first;
            int cnt=it->second;
            if(mp.count(num+1)){    //如果存在等於 num+1 的數
                maxLen=max(maxLen, cnt+mp[num+1]);  //計算最長合法子序列長度(進行比較)
            }
        }
        return maxLen;
    }
};