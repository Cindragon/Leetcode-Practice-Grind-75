class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<= merged.back()[1]){
                merged.back()[1]=max(merged.back()[1], intervals[i][1]);
            }
            else{
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};

/*
一樣用貪心算法，找到重疊的區間之後
若是區間有重疊的部分就進行合併，不然就加入新的區間
最後回傳合併過後的區間
*/