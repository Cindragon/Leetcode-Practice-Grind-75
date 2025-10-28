class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        int left=0;
        int right=sum;
        int ans=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0 && abs(right-left)<=1){
                if(abs(right-left)==1)  ans+=1;
                else    ans+=2;
            }
            left+=nums[i];
            right-=nums[i];
        }
        return ans;
    }
};
/*
用左右和的概念來解這題，左邊是前面各個數的總和，右邊是總和減掉左邊
如果遇到元素為 0 且左右兩邊相減 <=1 時計算 ans
left-right==1 ans+=1 left==right ans+=2
最後更新left 跟 right 並回傳 ans;
*/