class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty()&&temperatures[i]>temperatures[st.top()]){
                res[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};


/*
透過單調棧的方式來處理(尋找右邊或左邊第一個比較大或比較小的數)
(在此用 T 簡寫 temperature)
首先定義一個 stack，用來儲存索引值，res 數組來計算答案
將第一個元素 push 進去 stack，用 for 迴圈遍歷整個數組
有三種情況(小於、等於、大於)
在小於等於的情況，直接將對應的索引值加入 stack
而在 T[i]>T[st.top()] 而且 stack 不為空時，代表找到了比T[st.top()]還要大的數
因此更新 res[st.top()]=i-st.top()，計算距離
最後回傳res
*/
