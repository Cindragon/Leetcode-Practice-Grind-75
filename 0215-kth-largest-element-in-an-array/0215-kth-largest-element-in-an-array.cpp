class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(const auto&n:nums){
            pq.push(n);
        }
        k-=1;
        while(k--){
            pq.pop();
        }
        return pq.top();
    }
};

/*
用 priority queue 的特性來進行分類(預設是大頂堆，越大的元素放越前面)
因此先將 nums 陣列的數輸入進去，
在 k 不為 0 的情況下，彈出 k-1 次後，堆頂元素剛好就是 第 k 大的值
*/