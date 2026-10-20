
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size() - 1;
        int cols = matrix[0].size() - 1;

        int lt = 0;

        while (lt <= rows) {
            int midt = lt + (rows - lt) / 2;

            if (matrix[midt][0] <= target &&
                matrix[midt][cols] >= target) {

                int l = 0, r = cols;

                while (l <= r) {
                    int mid = l + (r - l) / 2;

                    if (matrix[midt][mid] == target)
                        return true;
                    else if (matrix[midt][mid] < target)
                        l = mid + 1;
                    else
                        r = mid - 1;
                }

                return false;
            }
            else if (target < matrix[midt][0]) {
                rows = midt - 1;
            }
            else {
                lt = midt + 1;
            }
        }

        return false;
    }
};
