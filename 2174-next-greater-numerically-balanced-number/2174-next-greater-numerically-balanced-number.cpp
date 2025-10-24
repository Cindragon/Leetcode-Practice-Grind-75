class Solution {
private:
    bool isbalanced(int n){
        string s=to_string(n);
        int cnt[10]={0};
        for(const auto&c:s){
            cnt[c-'0']++;
        }
        for(int i=0;i<10;++i){
            if(cnt[i]!=0 && cnt[i]!=i)   return false;
        }
        return true;
    }
public:
    int nextBeautifulNumber(int n) {
        int m=n+1;
        while(!isbalanced(m)){
            m++;
        }
        return m;
    }
};

/*
用一個回溯法的方式
先將 n+1 (因為要找比n還要大的平衡數)
接著如果 isblanced(m) return m
isblance函式：
    將數字變成字串，透過陣列來統計各個數字出現的次數
    若是其次數不為0且其不等於其索引值，直接回傳 false
    最後驗證完之後回傳 true;
*/