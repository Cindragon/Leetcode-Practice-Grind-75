class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> st;  //單調遞減棧，儲存的是索引值
        st.push(0);
        for(int i=1;i<nums.size()*2;i++){
            while(!st.empty()&&nums[i%nums.size()]>nums[st.top()]){
                res[st.top()]=nums[i%nums.size()];
                st.pop();
            }
            st.push(i%nums.size());
        }
        return res;
    }
};

/*
這題跟下個更大的數 I 很像，只是變成要在環狀數組中找到下一個更大的數
因為是環狀陣列，我們可以模擬走兩圈來處理。
   => 實際上跑 2 * n 次，用 i % n 當作實際索引。

讓 i 變成除以 nums.size() 的餘數，接著一樣把較大的數字輸入進 res
最後回傳 res 即可 
*/