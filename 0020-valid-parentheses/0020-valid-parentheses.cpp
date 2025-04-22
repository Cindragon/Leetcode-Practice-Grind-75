class Solution {
public:
    bool isValid(string s) {
        stack<char> ans;
        if(s.size()%2!=0) return false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                ans.push(s[i]);
            }
            else{
                if (ans.empty()) return false; //避免 ans.top()出錯
                char topc=ans.top();
                if(s[i]==')'&&topc=='('||s[i]==']'&&topc=='['||s[i]=='}'&&topc=='{'){
                    ans.pop();
                }
                else
                    return false; //括號最後不匹配的話直接回傳false(代表原本的括號就不對)
            }
        }
        return ans.empty(); //看是否為空(如果括號有多就不會是空)
    }
};