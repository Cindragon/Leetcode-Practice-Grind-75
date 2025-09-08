class Solution {
public:
    static bool cmp(vector<int>&p1, vector<int>&p2){
        return p1[0]==p2[0] ? p1[1]>p2[1] : p1[0]<p2[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int ans=0, n=points.size();
        for(int i=0;i<n-1;i++){
            int minY=INT_MIN;
            for(int j=i+1;j<n;j++){
                if(points[i][1]>=points[j][1]&&points[j][1]>minY){
                    ans++;
                    minY=points[j][1];
                }
            }
        }
        return ans;
    }
};