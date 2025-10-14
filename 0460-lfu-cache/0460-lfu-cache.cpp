class LFUCache {
private:
    struct Node{
        int key;
        int value;
        int freq;
        Node(int k, int v, int f=1):key(k), value(v), freq(f){}
    };
    int capacity;
    unordered_map<int, list<Node>::iterator> mp; //mp[key]直接指向該節點在 freqTable[freq] 的 list 裡的位置
    unordered_map<int, list<Node>> freqTable;   //
    int minFreq;    //最少使用次數
public:
    LFUCache(int capacity) {
        this->capacity=capacity;
        minFreq=0; //初始化為0
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())  return -1;
        auto it=mp[key];
        Node node=*it;
        int oldFreq=node.freq;
        freqTable[oldFreq].erase(it);
        if(freqTable[oldFreq].empty()){
            freqTable.erase(oldFreq);
            if(oldFreq==minFreq) minFreq++;
        }
        node.freq++;
        freqTable[node.freq].push_front(node);
        mp[key]=freqTable[node.freq].begin();
        return node.value;
    }
    
    void put(int key, int value) {
        if(capacity==0) return;
        if(mp.find(key)!=mp.end()){
            auto it=mp[key];
            Node node=*it;
            int oldFreq=node.freq;
            freqTable[oldFreq].erase(it);
            if(freqTable[oldFreq].empty()){
                freqTable.erase(oldFreq);
                if(oldFreq==minFreq)    minFreq++;
            }
            node.value=value;
            node.freq++;
            freqTable[node.freq].push_front(node);
            mp[key]=freqTable[node.freq].begin();
            return;
        }
        if(mp.size()==capacity){
            auto &listReq=freqTable[minFreq];
            Node delNode=listReq.back();
            mp.erase(delNode.key);
            listReq.pop_back();
            if(listReq.empty()) freqTable.erase(minFreq);
        }
        Node ptr(key, value, 1);
        freqTable[1].push_front(ptr);
        mp[key]=freqTable[1].begin();
        minFreq=1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 /*
 從 LCU 變形而來的題目，但是多了一個 freq 的參數，用來記錄這個數字被用了幾次
 不需要 dummyHead 跟 dummyTail，但需要記錄最小頻率(用來刪除最少使用頻率的元素)
 freqTable 紀錄的是使用次數有幾個 Node(如{1:10, 20}, {2:30})，
 mp 則是用來記錄並且指向各節點在 freqTable[freq] 的 list 裡的位置

 get(key)：如果沒有這個 key return -1
 有的話就將其使用頻率+1，並且加入到該使用頻率 list 的最前端
 也要記得先將舊的 Node 的 key 刪掉，如果其頻率(oldFreq)的list 為空則直接刪除，若 oldFreq==minFreq，則 minFreq++

 put(key)：如果沒有這個 key 直接 return
 若是加入原有的 key 要更新 value 的話，則跟 get 的操作一樣，需要將舊的 Node 刪掉，並且將其使用頻率+1，
 並且加入到新使用頻率 list 的最前端
 如果已經滿了，那就把最少使用次數的 Node 的尾巴刪除
 (auto &listReq=freqTable[minFreq]、Node delNode=listReq.back();)
 */