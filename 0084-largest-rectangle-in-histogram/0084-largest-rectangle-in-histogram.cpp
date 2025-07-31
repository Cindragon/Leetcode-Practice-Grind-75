class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        st.push(0);
        int res=0;
        for(int i=1;i<heights.size();i++){
            while(!st.empty()&&heights[i]<heights[st.top()]){
                int mid=st.top();
                st.pop();
                int h=heights[mid];
                int left=st.top();
                int right=i;
                int w=right-left-1;
                res=max(res, w*h);
            }
            st.push(i);
        }
        return res;
    }
};

/*
這題也可以用單調棧的方式來處理，跟接雨水不一樣的是，
我們需要找到當前元素左邊跟右邊比他小的第一個值，才能計算面積
因此透過stack來儲存索引值，並且為了簡化邊界條件處理，在原本的數組前後加入 0 
可以保證：所有柱子都會在某個時刻被彈出並計算面積，這樣你就不需要最後掃描棧中是否還有剩下的元素了。
一樣會有三種情況：大於、等於以及小於
在小於的情況：
    stack 當前的索引值便為中間元素(mid)
    高度(h)則是當前 height[mid] 的數值，寬度(w)則是兩邊索引值相減再減一
    最大長方形面積再透過比較獲得最大值
並且持續加入索引值，最後回傳 res 
*/