class Solution {
public:
    string longestPalindrome(string s) {
        int res_len=1;
        int start=0;
        int n=s.size();
        if(n==0) return "";
        for(int i=0;i<n;i++){
            int left=i;
            int right=i;
            while(left>=0 && right<n && s[left]==s[right]){
                if(right-left+1>res_len){
                    res_len=right-left+1;
                    start=left;
                }
                left--;
                right++;
            }
            left=i;
            right=i+1;
            while(left>=0 && right<n &&s[left]==s[right]){
                if(right-left+1>res_len){
                    res_len=right-left+1;
                    start=left;
                }
                left--;
                right++;
            }
            
        }
    return s.substr(start, res_len);
    }
};
/*
使用中心擴散法，用一個迴圈遍歷字串中的所有起點
分為奇數跟偶數的做法

奇數：
    left=i, right=i(從同一點出發)
    在 left>=0 且 right<s.size() 且s[left]==s[right]
    如果right-left+1的長度比最長回文字串大，更新長度
    並更新最長子字串的起點
    接著 left-- right++ (繼續找)
偶數：
    left=i, right=i+1(左右兩邊)
    跟奇數一樣的規則

最後回傳s.substr(start, res_len)
*/