class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int up = 0;
        int down = 0;
        int peak = 0;
        int total = 1;

        for(int i = 1; i < n; i++) {

            if(ratings[i] > ratings[i-1]) {
                up++;
                peak = up;
                down = 0;

                total += 1 + up;
            }

            else if(ratings[i] < ratings[i-1]) {
                up = 0;
                down++;

                total += 1 + down;

                if(down <= peak) {
                    total--;
                }
            }

            else {
                up = 0;
                down = 0;
                peak = 0;
                total++;
            }
        }

        return total;
    }
};