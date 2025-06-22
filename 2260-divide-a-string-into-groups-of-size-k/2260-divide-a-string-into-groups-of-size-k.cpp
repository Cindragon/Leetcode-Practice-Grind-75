class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        string ds;
        for(const auto&c:s){
            ds+=c;
            if(ds.size()==k){
                res.push_back(ds);
                ds.clear();
            }
        }
        if(!ds.empty()){
            ds.append(k-ds.size(), fill);
            res.push_back(ds);
        }
        return res;
    }
};