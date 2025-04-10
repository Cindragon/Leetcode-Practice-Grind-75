class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        if(intervals.size()==0) return merged;
        sort(intervals.begin(), intervals.end());
        vector<int> temps=intervals[0];
        for(const auto& it:intervals){
            if(it[0]<=temps[1]){
                temps[1]=max(it[1], temps[1]);
            }
            else{
                merged.push_back(temps);
                temps=it;
            }
        }
        merged.push_back(temps);
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
