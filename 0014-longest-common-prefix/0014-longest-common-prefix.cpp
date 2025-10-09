class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        int length=ans.size();
        for(int i=1;i<strs.size();++i){
            string temp=strs[i];
            while(length>temp.size()||ans!=temp.substr(0, length)){
                length--;
                if(length==0){
                    return "";
                }
                ans=ans.substr(0, length);
            }
        }
        return ans;
    }
};

/*
用第一個字串 ans 去跟後面的其他字串做比較
取出要比較的字串 temp
如果 ans 長度比較長或是 ans!=temp 的子字串
length--，如果length==0，直接回傳空字串
否則的話 ans=ans.substr(0, length)
*/