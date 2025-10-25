class Solution {
public:
    int totalMoney(int n) {
        vector<int> ans(n+1,0);
        int res=0;
        for(int i=1;i<=n;++i){
            if(i<=7){
                ans[i]=i;
            }
            else{
                ans[i]=ans[i-7]+1;
            }
            res+=ans[i];
        }
        return res;
    }
};