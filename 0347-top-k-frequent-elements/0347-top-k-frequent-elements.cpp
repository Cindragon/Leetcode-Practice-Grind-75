class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans(k);
        unordered_map<int, int> mp;
        for(const auto&i:nums){
            mp[i]++;
        }
        auto cmp=[](const pair<int, int>&a, const pair<int, int>&b){
            return a.second>b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pri_que(cmp);
        for(const auto&it:mp){
            pri_que.push(it);
            if(pri_que.size()>k){
                pri_que.pop();
            }
        }
        for(int i=k-1;i>=0;i--){
            ans[i]=pri_que.top().first;
            pri_que.pop();
        }
        return ans;
    }
};

/*
先用 map 來遍歷數組中的元素頻率
接下來用最小堆(Min-Heap)來對各元素出現的頻率做統計 (透過 priority_que 來設計)
把出現頻率從少排到多，並且透過 lambda 寫 cmp 的比較函式來做排序(不需要再多一個class)
在迴圈中遍歷 map，將 map 的元素 push 進去 pri_que 中
若是pri_que的大小>k，就將最頂端的元素(出現頻率最少的元素) pop 出去
最後用 vector 儲存pri_que.top().first()，然後再pop()
*/
