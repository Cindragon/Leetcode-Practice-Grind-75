class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        int ans=0;
        int n=s.size();
        for(int i=0, j=0;j<n;j++){
            if(mpp[s[j]]>0){
                i=max(mpp[s[j]], i);
            }
            ans=max(ans, j-i+1);
            mpp[s[j]]=j+1;
        }
        return ans;
    }
};

/*
運用滑動窗口跟map來作答
用mpp記錄每個字元上次出現的位置(index+1)
透過 for 迴圈遍歷整個字串：
- 如果當前字元未重複出現，則更新當前最長不重複子字串長度（ans）。
- 如果發現當前字元已出現過（mpp[s[j]] > 0），
  說明當前窗口內出現了重複字元，
  這時需更新滑動窗口的起點 i，
  將其移動到該重複字元上次出現位置的下一位，
  也就是 i = max(i, mpp[s[j]])。
每次都更新 mpp 中當前字元的位置為 j + 1，
最後回傳ans
*/