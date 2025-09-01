class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n), ans(n);
        int product=1;
        for(int i=0;i<nums.size();i++){
            prefix[i]=product;
            product*=nums[i];
        }
        product=1;
        for(int i=prefix.size()-1;i>=0;i--){
            ans[i]=product*prefix[i];
            product*=nums[i];
        }
        return ans;
    }
};

/*
建立兩個陣列：
    prefix：儲存每個位置左邊所有數字的乘積
    ans：儲存最終答案

第一次從前往後遍歷：
    prefix[i] = nums[0] * nums[1] * ... * nums[i-1]
    等於「當前位置左邊的乘積」

第二次從後往前遍歷：
    用一個變數 product 紀錄右邊所有數字的乘積
    將左邊的乘積與右邊的乘積相乘，最後輸出 ans
*/