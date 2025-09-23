class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[right]>nums[mid]){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return nums[left];
    }
};

/*
這次的陣列是有經過變換的，我們要找的是其中最小的值
首先用 Binary Search 的方式找到中間值，並且跟最右邊的值相比
    如果最右邊的值大於中間值，代表最小值在中間值的左邊
    反之則是往中間的的右邊找
最後回傳 nums[left]
*/