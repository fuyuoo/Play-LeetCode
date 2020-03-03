class Solution {
private:
    void fillfloor(vector<vector<int>>& image, int x, int y, int newColor,int targetColor){
        if(x >=0 && x < image.size() && y >=0 && y <image[0].size() && image[x][y] == targetColor){
            image[x][y] = newColor;
            fillfloor(image, x+1, y, newColor, targetColor);
            fillfloor(image, x-1, y, newColor, targetColor);
            fillfloor(image, x, y+1, newColor, targetColor);
            fillfloor(image, x, y-1, newColor, targetColor);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int targetColor = image[sr][sc];
        if(targetColor != newColor)
            fillfloor(image, sr, sc, newColor, targetColor);
        return image;
    }
};