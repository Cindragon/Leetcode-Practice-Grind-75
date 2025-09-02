class Solution {
public:
    static bool cmp(vector<int>&p1, vector<int>&p2){
        if(p1[0]==p2[0]){
            return p1[1]<p2[1];
        }
        else{
            return p1[0]>p2[0];
        }
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size(), ans=0;
        sort(points.begin(), points.end(), cmp);
        for(int i=0;i<n-1;i++){
            int minY=INT_MAX;
            for(int j=i+1;j<n;j++){
                if(points[j][1]>=points[i][1] && points[j][1]<minY){
                    ans++;
                    minY=points[j][1];
                }
            }
        }
        return ans;
    }
};

/*
先將所有點進行比較(cmp)，x 越大越前面，若 x 相等，則 y 越小越前面。
這樣可保證對於每個點 i，往後掃描的點 j 一定滿足 xj <= xi。
接著開始由左至右遍歷陣列，開始找組合的數量
minY 則是目前遇到的最低 y（最低障礙）
- 條件1：points[j].y >= points[i].y （j 在 i 的右上方或同高位置）
- 條件2：points[j].y < minY （確保 j 沒有被更低的點擋住）
代表找到一個組合，而且要更新 minY，以免被形成的矩形面積蓋住， j 本身變成新的「最低障礙」，會遮擋後面更高的點。。
*/