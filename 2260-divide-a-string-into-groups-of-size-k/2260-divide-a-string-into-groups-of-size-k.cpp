class Solution {
public:

    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        string ds;
        int n=s.size()-1;
        for(int i=0;i<s.size();i++){
            if(ds.size()==k){
                res.push_back(ds);
                ds.clear();
            }
            ds+=s[i];
        }
        while(ds.size()<k){
            ds+=fill;
        }
        res.push_back(ds);
        return res;
    }
};