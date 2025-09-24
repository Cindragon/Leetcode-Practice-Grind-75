class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    KthLargest(int k, vector<int>& nums):k(k) {
        for(const auto&n:nums){
            //add(n)
            if(minHeap.size()<k){
                minHeap.push(n);
            }
            else if(n>minHeap.top()){
                minHeap.push(n);
                if(minHeap.size()>k){
                    minHeap.pop();
                }
            }
        }
    }
    
    int add(int val) {
        if(minHeap.size()<k){
            minHeap.push(val);
        }
        else if(val>minHeap.top()){
            minHeap.push(val);
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

 /*
 因為要找第 k 大的元素，我們可以維護一個大小為 k 的小頂堆 (min-heap)。
 - 小頂堆頂端 (top) 代表目前堆中最小的元素。
 - 當遇到更大的數字時，就把堆頂 (較小的數) pop() 掉，再 push 新數字。
 - 這樣能保證堆內永遠只保留「目前最大的 k 個元素」。
 最後，minHeap.top() 就是整體的第 k 大元素。
 */