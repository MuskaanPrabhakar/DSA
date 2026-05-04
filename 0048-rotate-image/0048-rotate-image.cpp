class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size()<=1) return;
        int i= matrix.size()/2;
        int n= matrix.size()-1;
        for(int k=0; k<i; k++){
            swap(matrix[k], matrix[n]);
            n--;
        }
        for(int k=0; k<matrix.size(); k++){
            for(int i=k+1;i<matrix.size();i++){
                swap(matrix[i][k],matrix[k][i]);
            }
        }
    }
};