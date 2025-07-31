class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxnum=nums[0];
        int length=0, temp=0;
        for(const auto&n:nums){
            if(n>maxnum)   maxnum=n;
        }
        for(const auto&n:nums){
            if(n==maxnum){
                temp++;
                length=max(temp, length);
            }
            else{
                temp=0;
            }
        }
        return length;
    }
};

/*
找到數組中最大的數(因為兩數做 Bitwise AND，只要不是相同的數，會變成比較小的那個數)
因此這題要求的是最大數值的最長連續子序長度為何
找到最大數之後重新進行迴圈，並且在遇到最大樹的時候進行計算
如果遇到非最大數的就重新計算
*/