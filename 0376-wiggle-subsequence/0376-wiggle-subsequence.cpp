class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int res=1;  //默認最右邊有一次擺盪(因為左右都算一次)
        int prediff=0;
        int curdiff=0;
        for(int i=0;i<nums.size()-1;i++){
            curdiff=nums[i+1]-nums[i];
            // 若發生正負號變化（擺動），則 res+1，並更新 prediff
            if((prediff>=0&&curdiff<0)||(prediff<=0&&curdiff>0)){
                res++;
                prediff=curdiff;    //有擺盪的話更新prediff(如果沒有擺盪的話不更新)
            }
        }
        return res;
    }
};

/*
這題一樣用貪心算法
需要算出擺盪的次數
用 prediff(前) 跟 curdiff(後) 來記錄擺盪的幅度
最後記錄擺盪的次數之後回傳
*/