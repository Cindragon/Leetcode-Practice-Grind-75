class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int curr=0, next=0, ans=0;
        for(int i=0;i<nums.size();i++){
            next=max(i+nums[i], next);
            if(i==curr){
                if(curr!=nums.size()-1){
                    ans++;
                    curr=next;
                    if(curr>=nums.size()) break;
                }
                else
                    break;
            }
        }
        return ans;
    }
};

/*
這題一樣用貪心算法來解決
需要注意的是除了看沒有跳到終點還要看最少的步數為何
設一個變量 curr 代表當前的覆蓋範圍、next 代表下一步要跳的範圍、ans代表步數
在遍歷整個數組的迴圈中
每個位置 i 嘗試更新 next = max(next, i + nums[i])
   → 代表你站在 i，可以跳到的最遠距離
接著判斷，如果i==curr(走完當前的範圍)
若是還沒到終點，步數再增加，並且將curr更新為next
若是大於等於數組範圍直接break，最後回傳ans(步數)
*/