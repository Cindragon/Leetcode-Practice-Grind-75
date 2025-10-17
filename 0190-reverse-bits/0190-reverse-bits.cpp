class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        for(int i=0;i<32;++i){
            ans<<=1;    //ans往左移一位
            ans|=(n&1); // 取出 n 的「最右邊」那一位，放到 ans 的最低位
            n>>=1;  //n 往右移一位
            //ans = (ans << 1) | ((n >> i) & 1);
        }
        return ans;
    }
};