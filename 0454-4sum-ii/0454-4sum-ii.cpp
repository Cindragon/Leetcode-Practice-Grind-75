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
兩個陣列為一組
用 unordered_map 來儲存
用兩個迴圈來遍歷第一組陣列兩數之和跟出現的次數
後面用兩個迴圈遍歷第二組陣列，如果 map 有 0-第二組兩數之和
就計算出現幾組後回傳
*/