class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp=nums;
        vector<int> res;
        sort(temp.begin(), temp.end());

        unordered_map<int, int> mp;
        for(int i=0;i<temp.size();i++){
            if(mp.find(temp[i])==mp.end()){
                mp[temp[i]]=i;
            }
        }
        for(const auto&n:nums){
            res.push_back(mp[n]);
        }
        return res;
    }
};

/*
除了暴力解還可以用 map 來找
先透過 temp 暫存原本的 nums 數組，並且進行排序
接著用 map 來儲存各個數值在 temp 數組裡的位置(代表有幾個數字比他大)
重複的數字就跳過(因此要從前往後遍歷)
最後將 mp 的值傳入 res
*/