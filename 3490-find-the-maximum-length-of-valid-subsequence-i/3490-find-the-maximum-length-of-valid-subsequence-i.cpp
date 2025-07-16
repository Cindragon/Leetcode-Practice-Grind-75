class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<int> sub(4, 0);
        for(const auto&n:nums){
            if(n%2==0){
                sub[0]++;   //偶數個數
                sub[2]=sub[3]+1;    //奇數結尾加上現在的偶數
            }
            else{
                sub[1]++;   //奇數個數
                sub[3]=sub[2]+1;    //偶數結尾加上現在的奇數
            }
        }
        return max({sub[0],sub[1], sub[2], sub[3]});
    }
};