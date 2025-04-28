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
        for(const auto&it:mp){
            pri_que.push(it);
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
/*
先用 map 來遍歷數組中的元素頻率
接下來用最小堆(Min-Heap)來對各元素出現的頻率做統計 (priority_que)
在迴圈中遍歷 map，將map的元素 push 進去pri_que中
若是pri_que的大小>k，就將最頂端的元素(出現頻率最少的元素) pop 出去
最後用 vector 儲存pri_que.top().first()，然後再pop()
*/