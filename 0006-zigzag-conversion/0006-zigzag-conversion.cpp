class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.size() <= numRows) return s;
        int cyclen=2*numRows-2;
        string ans;
        for(int row=0;row<numRows;++row){
            for(int i=0;i+row<s.size();i+=cyclen){
                ans+=s[i+row];
                if(row!=0 && row!=numRows-1 && i+cyclen-row<s.size()){  //不是第一行或最後一行時
                    ans+=s[i+cyclen-row];
                }
            }
        }
        return ans;
    }
};