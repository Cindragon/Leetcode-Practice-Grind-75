class MedianFinder {
private:
    priority_queue<int> maxHeap; // 最大堆，保存小的一半
    priority_queue<int, vector<int>, greater<int>> minHeap;// 最小堆，保存大的一半
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty()||num<=maxHeap.top()){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }
        if(maxHeap.size()>minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(maxHeap.size()<minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size()==minHeap.size()){
            return double(maxHeap.top()+minHeap.top())/2.0;
        }
        else
            return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

 /*
 在實作的時候，分成兩堆，一堆是比較小的，另一堆是比較大的
 而 maxHeap 存的是比較小的一半，這樣其中最大的值就會在 maxHeap.top()
 同理，minHeap 存的是比較大的一半，這樣最小的值就會在 minHeap.top()
 並且讓兩邊大小盡量相等，如果是奇數就放到 maxHeap 中，這樣就可以直接回傳 maxHeap.top()
 */