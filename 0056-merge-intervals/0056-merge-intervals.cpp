class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        int n=intervals.size();
        if(n==0) return merged;
        sort(intervals.begin(), intervals.end());
        merged.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=merged.back()[1]){
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            }
            else{
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};