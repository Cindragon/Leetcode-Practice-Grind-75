class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        int n=nums.size();
        unordered_map<int, int> mp;
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>,  greater<>> minHeap;

        for(int i=0;i<k;++i){
            maxHeap.push(nums[i]);
        }
        for(int i=0;i<k/2;i++){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        for(int i=k;i<n;++i){
            if(k&1){
                ans.push_back(maxHeap.top()*1.0);
            }
            else{
                ans.push_back(((double)maxHeap.top()+(double)minHeap.top())/2.0);
            }
            int p=nums[i-k], q=nums[i];
            int balance=0;
            if(p<=maxHeap.top()){
                balance--;
                if(p==maxHeap.top()){
                    maxHeap.pop();
                }
                else    mp[p]++;
            }
            else{
                balance++;
                if(p==minHeap.top()){
                    minHeap.pop();
                }
                else    mp[p]++;
            }
            if(!maxHeap.empty() && q<=maxHeap.top()){
                maxHeap.push(q);
                balance++;
            }
            else{
                minHeap.push(q);
                balance--;
            }
            if(balance<0){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            else if(balance>0){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            while(!maxHeap.empty()&& mp[maxHeap.top()]){
                mp[maxHeap.top()]--;
                maxHeap.pop();
            }
            while(!minHeap.empty()&& mp[minHeap.top()]){
                mp[minHeap.top()]--;
                minHeap.pop();
            }
        }
        if(k&1){
            ans.push_back(maxHeap.top()*1.0);
        }
        else{
            ans.push_back(((double)maxHeap.top()+(double)minHeap.top())/2.0);
        }
        return ans;
    }
};