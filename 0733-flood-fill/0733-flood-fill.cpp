class Solution {
private:
    int m, n;
    vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<int>>& image, int i, int j, int newColor, int oldColor){
        if(i<0||i>=m||j<0||j>=n||image[i][j]!=oldColor) return;
        image[i][j]=newColor;
        for(const auto&d:dir){
            dfs(image, i+d.first, j+d.second, newColor, oldColor);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m=image.size();
        n=image[0].size();
        int oldColor=image[sr][sc];
        if(oldColor==color) return image;
        dfs(image, sr, sc, color, oldColor);
        return image;
    }
};