class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> seen;
        for(const auto&n:nums){
            if(n>0) seen.insert(n);
        }
        int ans=1;
        while(seen.count(ans)){
            ans++;
        }
        return ans;
    }
};