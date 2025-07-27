class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> arr;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]) continue;
            arr.push_back(nums[i]);
        }
        arr.push_back(nums[nums.size()-1]);
        int res=0;
        for(int i=1;i<arr.size()-1;i++){
            if(arr[i-1]<arr[i]&&arr[i]>arr[i+1]){   //計算山峰
                res++;
            }
            else if(arr[i-1]>arr[i]&&arr[i]<arr[i+1]){  //計算山谷
                res++;
            }
        }
        return res;
    }
};
/*
先將重複的值剃除(避免影響計算結果)
接著將值進行比較，並且將山峰跟山谷的數量進行加總
最後回傳 res
*/