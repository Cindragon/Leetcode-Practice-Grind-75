class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int res=1;
        int prediff=0;
        int curdiff=0;
        for(int i=0;i<nums.size()-1;i++){
            curdiff=nums[i+1]-nums[i];
            if((prediff>=0&&curdiff<0)||(prediff<=0&&curdiff>0)){
                res++;
                prediff=curdiff;
            }
        }
        return res;
    }
};