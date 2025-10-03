class RandomizedSet {
    unordered_map<int, int> mp;
    vector<int> nums;  //存元素
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;
        nums.push_back(val);
        mp[val]=nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val))   return false;
        int idx=mp[val];
        int last=nums.back();
        nums[idx]=last;
        mp[last]=idx;
        nums.pop_back();
        mp.erase(val);
        return true;

    }
    
    int getRandom() {
        int idx=rand()%nums.size();
        return nums[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

 /*
 要用到 map 跟 vector 來分別儲存加入的數字以及索引值

 insert:
    如果map已經有了 val，就不用再加入
    在 map 沒有的情況下，先將這個數加入 nums，接著透過 nums 的索引值，將 val 加入到 map
    (每次只插入一個數值)
remove:
    如果map沒有這個數值，回傳false
    用 idx 存 val 的索引值，並且用 last 代表 nums 最後一個數字(取代要被移除的元素)
    接著將 nums[idx](要被 remove 的 val) 取代成 last，然後把 map[last]的索引值取代為 idx
    最後 nums.pop_back()，mp.erase(val) return true
getRandom:
    用亂數來指定nums中的隨意數字
 */