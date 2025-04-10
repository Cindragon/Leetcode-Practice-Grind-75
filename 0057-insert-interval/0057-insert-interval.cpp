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
/*
用三個 while 迴圈去找合併後的最大新區段並最後加入到 merged 裡面

第一個 while (把在newInteval前面的都加進去)
比較 interval[i][1] 有沒有小於 newInterval[0] (代表沒有重疊)

第二個 while (把有與newInterval重疊的區段整合在一起為新的區段)
比較 interval[i][0] 有沒有小於或等於 newInterval[1] (代表可以重整)(前面沒有重疊的都跑完了)
用 min 跟max 找最大最小值
跑完用push_back進去

第三個 while (把剩下的都放進去)
最後把沒跑到的放進去
*/
