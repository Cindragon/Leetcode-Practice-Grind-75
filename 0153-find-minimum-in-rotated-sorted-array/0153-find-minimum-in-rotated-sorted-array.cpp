class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            // 如果中間值比最右邊小，表示右半是排序好的
            // 所以最小值一定在 [left, mid] 之間
            if(nums[right]>nums[mid]){
                right=mid;
            }
            // 否則，最小值一定在 [mid+1, right] 之間
            else{
                left=mid+1;
            }
        }
        // 當 left == right 時，指向的就是最小值
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