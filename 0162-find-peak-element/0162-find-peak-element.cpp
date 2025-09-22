class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]>nums[mid+1]){
                right=mid;  //左邊一定有一個峰值
            }
            else left=mid+1;    //右邊一定有一個峰值
        }
        return left;    //在 left=right 的時候會找到峰值
    }
};

/*
用 Binary Search 的方式來找到其中一個峰值
從左右兩邊來找中間的峰值元素
    如果中間比右邊大，代表峰值在左邊
    如果中間比左邊大，代表峰值在右邊
最後在 left=right 的情況下就能至少找到一個 peak element 了
*/