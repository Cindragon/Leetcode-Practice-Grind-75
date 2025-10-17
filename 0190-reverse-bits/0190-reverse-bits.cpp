class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        for(int i=0;i<32;++i){
            ans<<=1;    //ans往左移一位
            ans|=(n&1); //ans 跟 n 最左邊的一位 bit 做 or
            n>>=1;  //n 往右移一位
            //ans = (ans << 1) | ((n >> i) & 1);
        }
        return ans;
    }
};