class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(!(k&1)||k%5==0)  return -1;
        int ans=1;
        int remainder=1%k;
        while(remainder!=0){
            remainder=(10*remainder+1)%k;
            ans+=1;
        }
        return ans;
    }
};

/*
*/