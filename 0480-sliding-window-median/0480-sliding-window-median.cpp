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

/*
跟 Leetcode 295有點相似，一樣是要用大頂堆(較小的一半)跟小頂堆(較大的一半)維持中位數
但不一樣的是要有一個map來做lazy deletion
1. 先將k個元素push進大頂堆中，並且再將較大的一半分配到小頂堆中
2. 先找到第一個中位數，接著開始進行插入跟刪除數字
    p 代表要刪除的數字，q 代表要加入的數字，balance 代表如果兩邊長度相差太大要進行平衡

    若是 p<=maxHeap.top(); 代表要從 maxHeap 中刪掉一個元素(左邊刪除一個) balance--
    如果等於 maxHeap.top() 才能直接 pop()，不然就是之後他變成 top 之後刪除(mp[p]++)

    反之則代表要從 min Heap 中刪掉一個元素(右邊刪除一個) balance++
    如果等於 minHeap.top() 一樣直接 pop()，或是 mp[p]++
3. 若是目前 maxHeap不為空 而且 q (要插入的元素) <= maxHeap，直接加到大頂堆，反之則加到小頂堆
   然後一樣要對 balance 做加減，(左邊多了一個 → balance++；右邊多一個 → balance--)

4. 若是 balance 一樣小於 0，代表從小頂堆刪除太多元素，大小堆要做長度平衡(透過 balance 去做)
5. 最後的兩個 while 則是 lazy delete 的做法，若是要刪除的元素變成了 top 就可以 pop 掉
6. 最後再加入一次中位數，回傳陣列
*/