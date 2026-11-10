class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        for (int i = 1; i < n - 1; i++) {
            int dx1 = coordinates[i][0] - coordinates[i - 1][0];
            int dy1 = coordinates[i][1] - coordinates[i - 1][1];
            int dx2 = coordinates[i + 1][0] - coordinates[i][0];
            int dy2 = coordinates[i + 1][1] - coordinates[i][1];
            if (dy1 * dx2 != dy2 * dx1) {
                return false;
            }
        }
        return true;
    }

}
;