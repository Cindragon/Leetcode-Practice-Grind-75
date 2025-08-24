class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> keep(n, 0), del(n, 0);
        int res=0;
        keep[0]=nums[0]==1?1:0;
        del[0]=0;
        for(int i=1;i<n;i++){
            if(nums[i]==1){
                keep[i]=keep[i-1]+1;
                del[i]=del[i-1]+1;
            }
            else{
                keep[i]=0;
                del[i]=keep[i-1];
            }
            res=max(res, del[i]);
        }
        return res;
    }
};

/*
用動態規劃的概念來解
DP 數組定義：keep(以 i 結尾，沒有刪除過元素 的最長連續 1 長度)，del(以 i 結尾，刪除過一個 0 元素的最長連續 1 長度)
遞推公式：
    如果 nums[i]=1，keep[i] 跟 del[i] 都等於前一個加一
    如果 nums[i]=0，keep[i]=0 (重新計算長度)，del=keep[i-1](刪掉這個 0 )
初始化：keep[0] 以 nums[0] 的元素決定，del[0]=0
遍歷順序：從 1 開始遍歷，遍歷到最後一個元素
用 res 來記錄最長的長度
*/

/*
也可以只用 del 跟 keep 兩個變數來儲存長度就好(只跟前一個元素的狀態有關)
for(const auto&n:nums){
    if(n==1){
        keep=keep+1
        del=del+1
    }
    else{
        del=keep
        keep=0
    }
    res=max(res, del)
}
if(res==nums.size())    return res-1(至少刪除一個元素)
*/