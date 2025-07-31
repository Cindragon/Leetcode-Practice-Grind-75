class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;
        int even=INT_MAX, odd=INT_MIN;
        for(const auto&n:s){
            mp[n]++;
        }
        auto iter=mp.begin();
        while(iter!=mp.end()){
            if(iter->second%2==1){
                odd=max(odd, iter->second);
            }
            else{
                even=min(even, iter->second);
            }
            iter++;
        }
        return odd-even;
    }
};