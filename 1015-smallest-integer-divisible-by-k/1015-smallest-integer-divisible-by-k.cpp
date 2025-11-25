class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(!(k&1)||k%5==0)  return -1;
        int ans=1;
        int remainder=1%k;
        while(remainder!=0){
            remainder=(10*remainder+1)%k;
            ans+=1;
            if(ans>k+1) return -1;
        }
        return ans;
    }
};

/*
在找的時候不要想著建立整個數列(1, 11, 111, 1111......)
而是從餘數去找(這樣remainder永遠都會在1~k-1之間)
而餘數最多就是k+1個，所以運算次數>k+1時，代表進入循環
直接回傳 -1(代表除不盡)，否則回傳ans
*/