class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int cover=0;
        for(int i=0;i<=cover;i++){
            cover=max(i+nums[i], cover);
            if(cover>=nums.size()-1) return  true;
        }
        return false;
    }
};

/*
一樣是使用貪心算法的方式，只要求能夠覆蓋到終點的最大範圍就好
設一個變量 cover，目前能跳到的最遠位置，接著透過迴圈來更新cover的範圍
cover=max(i+nums[i], cover)
意思是：從位置 i 最遠能跳到 i + nums[i]，我們要看是否能讓 cover 向右延伸。
如果大於等於數組範圍就 return true
不然就 return false
*/