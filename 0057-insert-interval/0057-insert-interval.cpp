class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> merged;
        int n=intervals.size();
        int i=0;
        while(i<n && intervals[i][1]<newInterval[0]){
            merged.push_back(intervals[i]);
            i++;
        }
        while(i<n&&intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(intervals[i][0], newInterval[0]);
            newInterval[1]=max(intervals[i][1], newInterval[1]);
            i++;
        }
        merged.push_back(newInterval);
        while(i<n){
            merged.push_back(intervals[i]);
            i++;
        }
        return merged;
    }
};