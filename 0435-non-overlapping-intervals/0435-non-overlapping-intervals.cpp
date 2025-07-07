class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int ans=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<intervals[i-1][1]){
                ans++;
                intervals[i][1]=min(intervals[i-1][1], intervals[i][1]);
            } 
        }
        return ans;
    }
};

/*
一樣用貪心算法(跟Leetcode 452 一樣)
求重疊的區間
如果說區間的左邊界<上一個區間的右邊界(說明他們有重疊) ans++
接著更新新的右邊界，找兩個區間右邊界的最小值。
最後再回傳ans
*/