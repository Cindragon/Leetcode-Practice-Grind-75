class Solution {
public:
    vector<string> res;
    void backtracking(string& s, int startIndex, int pointSum){
        if(pointSum==3){
            if(isValid(s, startIndex, s.size()-1)){
                res.push_back(s);
            }
            return;
        }
        for(int i=startIndex;i<s.size();i++){
            if(isValid(s, startIndex, i)){
                s.insert(s.begin()+i+1, '.');
                pointSum+=1;
                backtracking(s, i+2, pointSum);
                s.erase(s.begin()+i+1);
                pointSum-=1;
            }
            else
                break;
        }
        return;
    }
    bool isValid(string& s, int start, int end){
        if(start>end) {
            return false;
        }
        if(s[start]=='0'&&start!=end){
            return false;
        }
        int sum=0;
        for(int i=start;i<=end;i++){
            if(s[i]>'9'||s[i]<'0'){
                return false;
            }
            sum=sum*10+(s[i]-'0');
            if(sum>255){
                return false;
            }
        }
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0, 0);
        return res;
    }
};