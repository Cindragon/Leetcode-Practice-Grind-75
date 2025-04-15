class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int slow=0;
        for(int fast=0;fast<n;fast++){
            if(s[fast]!=' '){
                if(slow!=0){
                    s[slow]=' ';
                    slow++;
                }
                while(fast<n&&s[fast]!=' '){
                    s[slow]=s[fast];
                    slow++;
                    fast++;
                }
            }
        }
        s.resize(slow);
        n=s.size();
        reverse(s.begin(),s.end());
        int start=0;
        for(int end=0;end<=n;end++){
            if(s[end]==' '||end==n){
                reverse(s.begin()+start, s.begin()+end);
                start=end+1;
            }
        }
        return s;
    }
};

/*
使用快慢指針（fast & slow）來處理字串

首先移除多餘的空格，並只保留單字間一個空格
fast 跟 slow 都從 0 開始
- 如果遇到不是空格的字元：
    若 slow 不等於 0，表示不是第一個單字，就先補一個空格。
    接著將整個單字逐字複製到 slow 的位置，並更新 slow

接下來要 resize s，然後整串進行翻轉

再次使用快慢指針，把每個單字各自翻轉回正確順序：
    若遇到空格或到字串尾端，就把當前單字進行 reverse。
    然後將 start 指向下一個單字的開頭。

最後回傳 s
*/
