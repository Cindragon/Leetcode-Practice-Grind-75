class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> ans;
        string str;
        for(const auto& c:s){
            if(!ans.empty()&&c==ans.top()){
                ans.pop();
            }
            else
                ans.push(c);
        }
        str.resize(ans.size());
        for(int i=ans.size()-1;i>=0;i--){
            str[i]=ans.top();
            ans.pop();
        }
        return str;
    }
};