class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> row;

        for (auto &x : reservedSeats) {
            int r = x[0];
            int s = x[1];

            row[r] |= (1 << (s - 1));
        }

        int ans = 0;

        ans = (n - row.size()) * 2;

        int left   = 0b00000011110;
        int middle = 0b0001111000;  
        int right  = 0b0111100000;  

        for (auto &[r, seats] : row) {
            if ((seats & left) == 0 &&
                (seats & right) == 0) {

                ans += 2;
            }
            else if ((seats & left) == 0 ||
                     (seats & middle) == 0 ||
                     (seats & right) == 0) {

                ans += 1;
            }
        }
        return ans;
    }
};