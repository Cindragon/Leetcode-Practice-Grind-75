class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg,pos;
        neg=binarysearch(nums, 0);
        pos=nums.size()-binarysearch(nums,1);
        return max(neg, pos);
    }
private: 
    int binarysearch(vector<int> &nums, int target){
        int left=0, right=nums.size()-1, middle, result=nums.size();
        while(left<=right){
            middle=(left+right)/2;
            if(nums[middle]<target){
                left=middle+1;
                cout<<left<<endl;
            }
            else {
                result=middle;
                right=middle-1;
            }
        }
        return result;
    }
};