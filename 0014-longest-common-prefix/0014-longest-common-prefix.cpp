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