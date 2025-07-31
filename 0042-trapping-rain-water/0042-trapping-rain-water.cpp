class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        st.push(0);
        int sum=0;
        for(int i=1;i<height.size();i++){
            if(height[i]<height[st.top()]){ //小於當前元素
                st.push(i);
            }
            else if(height[i]==height[st.top()]){   //等於(將原本的彈出加入新的索引值)
                st.pop();   
                st.push(i);
            }
            else{
                while(!st.empty()&&height[i]>height[st.top()]){
                    //彈出棧頂當作底部，與新的棧頂（左邊界）及當前柱子（右邊界）計算雨水
                    int mid=st.top();
                    st.pop();
                    if(!st.empty()){
                        int h=min(height[i], height[st.top()])-height[mid]; //求雨水高度
                        int w=i-st.top()-1; //求寬度(要再-1因為我們要求的是中間寬度)
                        sum+=h*w;
                    }
                }
                st.push(i);
            }
        }
        return sum;
    }
};

/*
這題也可以用單調棧的方式來處理，我們需要找到當前元素左邊跟右邊比他大的第一個值
因此透過stack來儲存索引值，並且計算面積
一樣會有三種情況：小於、等於以及大於
在小於的情況將遍歷到的索引值加入 stack，在等於時彈出原本的元素再加入新的索引值(避免寬度錯誤)
最後在stack不為空且當前元素大於stack中的元素時
stack 當前的索引值便為中間元素(mid)
高度(h)則是要找到兩邊最小值之後減去底部高度，寬度(w)則是兩邊索引值相減再減一
雨水面積就是直接相加 sum+=h*w
最後回傳 sum 
*/