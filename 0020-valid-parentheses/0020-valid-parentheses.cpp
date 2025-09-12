class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s.size()%2!=0)   return false;
        for(const auto&c:s){
            if(c == '(')  st.push(')');
            else if(c == '[')   st.push(']');
            else if(c == '{')   st.push('}');
            else if(st.empty()||st.top() != c){
                return false;
            }
            else    st.pop();
        }
        return st.empty();
    }
};

/*
用 stack 來進行括號配對，若是 s 字串為奇數就直接 return false
接著遍歷整個字符串，若是遇到左半部就將右半部 push 進 stack
接著若是遇到右半部，如果跟 stack.top() 不同就 return false(因為順序要一樣)
若相同就 pop 出來，最後回傳看st是否為空(代表都配對完畢)

(另一種寫法)
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

*/