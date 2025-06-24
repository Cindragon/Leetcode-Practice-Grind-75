class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        int n=nums.size();
        int start=0;
        for(int i=0;i<n;i++){   //對所有 nums[i]==key，將距離為 k 的索引值 start 加入 res
            if(nums[i]==key){
                int left=max(start, i-k);
                int right=min(i+k, n-1);
                while(start<=right){
                    if(start>=left){
                        res.push_back(start);
                    }
                    start++;
                }
            }
        }
        return res;
    }
};

/*
使用雙指針的解法
int start作為記錄索引值位置
接著進行迴圈
如果nums[i]==key，要開始找到邊界
left=max(start, i-k) 左閉右閉，找到要加入的起始位置（不能比上次處理過的還小）
right=min(i+, n-1) 一樣左閉右閉，找到終止位置（不能超出陣列邊界）
接著使用 while (start <= right) 掃描範圍內的索引
如果start>=left(在區間內)，就把 start 加入 res，並且start++
*/