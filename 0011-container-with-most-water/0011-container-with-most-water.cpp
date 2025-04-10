class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1;
        int maxh=0, area=0, con;
        while(l<r){
            maxh=min(height[l], height[r]);
            con=maxh*(r-l);
            area=max(con, area);
            if(height[l]<height[r]){
                l++;
            }
            else
                r--;
        }
        return area;
    }
};