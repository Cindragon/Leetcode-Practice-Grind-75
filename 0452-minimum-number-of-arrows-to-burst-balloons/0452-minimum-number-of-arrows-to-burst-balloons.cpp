class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[0]<b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0) return 0;
        sort(points.begin(), points.end(), cmp);
        int ans=1;
        for(int i=1;i<points.size();i++){
            if(points[i][0]>points[i-1][1]){
                ans++;
            }
            else{
                points[i][1]=min(points[i-1][1], points[i][1]);
            }
        }
        return ans;
    }
};

/*
貪心算法：用最少的箭射完所有的氣球
在計算的時候先將所有區間以左邊邊界進行排序，起始弓箭為1(最少需要一支弓箭)
接著使用迴圈，如果現在這個區間的左邊界>上一個區間的右邊界(沒有重疊)
說明需要再多一支弓箭
有重疊的話，則是更新兩個區間右邊界的最小值
最後回傳ans
*/