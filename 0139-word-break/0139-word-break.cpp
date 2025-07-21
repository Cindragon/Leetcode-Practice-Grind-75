class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1, false);
        dp[0]=true;
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<i;j++){
                string word=s.substr(j, i-j);
                if(wordSet.find(word)!=wordSet.end()&&dp[j]) dp[i]=true;
            }
        }
        return dp[s.size()];
    }
};

/*
跟LeetCode 131 分割回文串很像，但這題可以用完全背包來節省運算時間
將 s的大小做為背包大小，將字典中的詞語做為物品
此外，由於詞語是有順序性的(為了要判斷是否等於字串)，因此要先遍歷背包再遍歷物品
dp 數組定義：在 i 長度的字串中，dp[i]=true，代表可以拆分為一個或是多個在字典中出現的詞語
將字典的字詞用作set以方便查找
遞推公式：如果確定dp[j] 是true，且 [j, i] 這個區間的⼦字串出現在字典裡，那麼dp[i]⼀定是true（j < i ）。
if([j, i] 這個區間的子字串出现在字典裡 && dp[j]是true) 那麼 dp[i] = true。
初始化：dp[0]=true，其他皆設為false(從遞推的過程去推理出來)
遍歷順序：由於我們要求的是排列，先遍歷背包再遍歷物品
並且在最後回傳dp[s.size()]
*/