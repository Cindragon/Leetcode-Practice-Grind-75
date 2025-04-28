class Solution {
public:
    deque<int> que;
    void pop(int val){
        if(!que.empty()&&val==que.front()){
            que.pop_front();
        }
    }
    void push(int val){
        while(!que.empty()&& val>que.back()){
            que.pop_back();
        }
        que.push_back(val);
    }
    int getMaxValue(){
        return que.front();
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(i>=k){
                pop(nums[i-k]);
            }
            push(nums[i]);
            if(i>=k-1){
                ans.push_back(getMaxValue());
            }
        }
        return ans;
    }
};