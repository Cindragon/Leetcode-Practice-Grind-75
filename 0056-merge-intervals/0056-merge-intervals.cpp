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

/*
要對區間先進行排序
用temp來存一開始的區間起始值
接下來用迴圈遍歷區間( auto it
如果元素[0]小於或等於temp[1]
那代表可以進行合併(用max來比it[1]跟temp[1]的大小)
或者不重複 那將temp push_back到merge interval
temp 等於it 後繼續比較
最後的temp也要記得加入到merge裡面。
*/
