class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int num1, num2;
        for(const auto&c:tokens){
            if(c=="+"||c=="-"||c=="*"||c=="/"){
                num1=st.top();
                st.pop();
                num2=st.top();
                st.pop();
                if(c=="+")  st.push(num2+num1);
                if(c=="-")  st.push(num2-num1);
                if(c=="*")  st.push(num2*num1);
                if(c=="/")  st.push(num2/num1);
            }
            else    st.push(stoi(c));
        }
        return st.top();
    }
};

/*
用stack來解題，遍歷所有元素
如果遇到運算符號就取出兩個元素，並判斷是哪個運算符號之後做運算(要記得順序不能顛倒)
並把運算結果再push回去stack方便下一次計算
遇到數字就push到stack裡面(要記得轉成int的形式)
最後回傳stack.top()
*/