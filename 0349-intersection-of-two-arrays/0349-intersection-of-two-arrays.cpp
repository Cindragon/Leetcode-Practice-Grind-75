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
選對結構很重要，使用unordered_set來對nums1進行hashtable的排列
接著遍歷nums2，如果nums2的元素在裡面就加到ans中
最後回傳vector形式的ans
*/