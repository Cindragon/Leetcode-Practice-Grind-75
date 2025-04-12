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

/*
另一種寫法
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int m=nums1.size(), n=nums2.size();
        int i=0, j=0;
        while(i<m&&j<n){
            if(nums1[i]>nums2[j]){
                j++;
            }
            else if(nums2[j]>nums1[i]){
                i++;
            }
            else{
                if(ans.empty()||ans.back()!=nums1[i]){
                    ans.push_back(nums1[i]);
                }
            }
            i++;
            j++;
        }
        return ans;
    }
};
*/