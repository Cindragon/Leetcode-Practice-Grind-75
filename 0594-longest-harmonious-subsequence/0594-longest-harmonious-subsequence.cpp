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
/*
使用sort+雙指標的方式，將兩數進行比較
   - 如果 nums[right] - nums[left] > 1，代表區間內數字差距太大，要縮小左界 → left++
   - 如果 nums[right] - nums[left] == 1，代表區間是合法的，計算長度 right - left + 1，更新 maxLen
最後return maxLen
*/