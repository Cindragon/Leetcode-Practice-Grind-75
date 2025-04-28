class Solution {
private:
    class MyQue{
    public:
        deque<int> que;
        void pop(int val){
            if(!que.empty()&&val==que.front()){
                que.pop_front();
            }
        }
        void push(int val){
            while(!que.empty()&&val>que.back()){
                que.pop_back();
            }
            que.push_back(val);
        }
        int getMaxValue(){
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQue que;
        vector<int> ans;
        for(int i=0;i<k;i++){
            que.push(nums[i]);
        }
        ans.push_back(que.getMaxValue());
        for(int i=k;i<nums.size();i++){
            que.pop(nums[i-k]); //將最前面的元素進行移除，移除舊的元素。
            que.push(nums[i]);
            ans.push_back(que.getMaxValue());
        }
        return ans;
    }
};

/*
使用 class 把自定義的 deque 功能做出來
MyQue 的 class 包含三個功能：pop()、push()、getMaxValue()
pop()：檢查最前面的元素是不是即將滑出窗口，如果是，就移除它。
push()：新元素進來時，從後面開始，把比自己小的元素全部踢掉，確保隊列是「從大到小」排列的。
getMaxValue()：回傳deque的最大值(也就是deque.front())

先將前 k 個元素放進去，然後記錄第一個滑動窗口的最大值
接下來從第 k 個元素開始遍歷
先移除deque最前面的元素，接著開始push，然後push_back(滑動窗口最大值)到ans
最後回傳ans
*/