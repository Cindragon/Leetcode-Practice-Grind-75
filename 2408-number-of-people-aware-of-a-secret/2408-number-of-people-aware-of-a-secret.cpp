class Solution {
public:
    const int MOD=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n+1, 0);
        dp[1]=1;
        long long share=0;
        for(int i=2;i<=n;i++){
            if(i-forget>=1){
                share=(share-dp[i-forget]+MOD)%MOD;
            }
            if(i-delay>=1){
                share=(share+dp[i-delay])%MOD;
            }
            dp[i]=share;
        }
        long long ans=0;
        for(int i=n-forget+1;i<=n;i++){
            ans=(ans+dp[i])%MOD;
        }
        return (int)ans;
    }
};

/*
動規五部曲的方式來解這道題目
1. 設定 dp 陣列：在第 i 天可以分享祕密的人數有 dp[i] 位
2. 遞推公式：設定一個變數share記錄目前可以分享祕密的人
    如果 i-forget>=1，代表有人開始忘記祕密了，因此share=(share-dp[i-forget]+MOD)%MOD
    如果 i-delay>=1，代表還可以繼續分享祕密，share=(share+dp[i-delay])%MOD
    dp[i]=share(目前可以分享的人數)
3. 初始化：第 1 天只有一個人知道祕密，因此dp[1]=1，其他皆設為0
4. 遍歷順序：從第2天開始計算第 i 天知道並可以分享祕密的人數，一直到第 n 天
最後透過 ans 來統計到第 n 天知道祕密的人。
*/