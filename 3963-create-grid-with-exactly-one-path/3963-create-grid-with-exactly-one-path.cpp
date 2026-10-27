class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid;
        for(int i=0; i<m;i++){
            grid.push_back("");
            for(int j=0; j<n;j++){
                if(i==0 || j==n-1) grid[i]+=".";
                else grid[i]+="#";
            }
        }
        return grid;
    }
};