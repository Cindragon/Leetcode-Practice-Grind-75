class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ans;
        unordered_set<int> nums1_set(nums1.begin(), nums1.end());
        for(const auto&n:nums2){
            if(nums1_set.find(n)!=nums1_set.end())
                ans.insert(n);
        }
        return vector<int>(ans.begin(), ans.end());
    }
};

/*
使用 unordered_set 將 nums1 存入哈希表中，方便快速查找元素（O(1) 時間複雜度）
接著遍歷 nums2，如果某個元素也存在於 nums1_set 中，就將其加入結果集合 ans（自動去重）
最後將結果集合轉換成 vector 並回傳
*/