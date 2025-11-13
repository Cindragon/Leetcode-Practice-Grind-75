class Solution {
public:
    int maxOperations(string s) {
        int count=0, ans=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='1'){
                count++;
            }
            else if(i>0&&s[i-1]=='1'){
                ans+=count;
            }
        }
        return ans;
    }
};

/*
這個問題主要用貪心的方式去解
從左到右遍歷字串，計算有幾個1
如果說在 i>0 而且 s[i-1]=='1' 的情況下，代表要先將前面所有的1都進行移動
因此 ans+=count
最後回傳 ans
*/