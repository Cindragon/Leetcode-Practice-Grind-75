class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count=0;
        unordered_map<int, int> res;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                int sum=nums1[i]+nums2[j];
                res[sum]++;
            }
        }
        for(int i=0;i<nums3.size();i++){
            for(int j=0;j<nums4.size();j++){
                int target=0-(nums3[i]+nums4[j]);
                //auto iter=res.find(target);
                if(res.find(target)!=res.end()){
                    //count+=iter->second;
                    count+=res[target];
                }
            }
        }
        return count;
    }
};

/*
將四個陣列分成兩組（nums1+nums2 和 nums3+nums4）

第一階段：
使用 unordered_map 記錄第一組中所有兩數之和 sum 以及該 sum 出現的次數。

第二階段：
遍歷第二組的所有兩數之和，設為 target。
若 map 中存在 target 的相反數（即 0 - target），
則表示有可組合成總和為 0 的組合，將其出現次數加總至計數器。

最後回傳總組合數。
*/