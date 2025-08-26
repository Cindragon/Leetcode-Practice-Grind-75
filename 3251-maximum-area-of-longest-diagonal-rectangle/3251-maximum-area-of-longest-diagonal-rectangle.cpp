class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxarea=0;
        int maxdiag=0;
        for(const auto&d:dimensions){
            int b=d[0], h=d[1];
            int diagonal=b*b+h*h;
            int area=b*h;
            if(diagonal>maxdiag){
                maxdiag=diagonal;
                maxarea=area;
            }
            else if(diagonal==maxdiag){
                maxarea=max(maxarea, area);
            }
        }
        return maxarea;
    }
};

/*
找到最長的那條對角線(比較平方相加的大小即可)
如果兩條對角線長度一樣，則比較三角形的面積並且回傳最大的三角形面積
*/