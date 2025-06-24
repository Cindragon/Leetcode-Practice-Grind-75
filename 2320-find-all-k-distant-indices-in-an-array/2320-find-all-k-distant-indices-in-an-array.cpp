class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        int n=nums.size();
        int nextStart=0;
        for(int i=0;i<n;i++){ //對於所有nums[i]==key的位置，將距離為k的索引值j加入res，並且避免重複
            if(nums[i]==key){
                int start=max(nextStart, i-k);
                int end=min(n-1, i+k);
                for(int j=start;j<=end;j++){
                    res.push_back(j);
                }
                nextStart=end+1;
            }

        }
        return res;
    }
};