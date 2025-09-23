class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())    return {-1, -1};
        int left=0, right=nums.size()-1, found=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                found=mid;
                break;
            }
            else if(nums[mid]>target)   right=mid-1;
            else    left=mid+1;
        }
        if(found==-1)   return {-1, -1};
        int start=found, end=found;
        while(start>0 && nums[start-1]==target)   start--;
        while(end<nums.size()-1 && nums[end+1]==target) end++;
        return {start, end};
    }
};
/*
先用 Binary Search 找到其中一個值
接下來再左右擴張，直到找到邊界為止
*/