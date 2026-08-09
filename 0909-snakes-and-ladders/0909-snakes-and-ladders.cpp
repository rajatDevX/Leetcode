class Solution {
public:

    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();

        queue<int> q;
        vector<int> visited(n * n + 1, false);

        q.push(1);
        visited[1] = true;

        int moves = 0;

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                int curr = q.front();
                q.pop();

                if(curr == n * n)
                    return moves;

                for(int dice = 1; dice <= 6; dice++) {

                    int next = curr + dice;

                    if(next > n * n)
                        continue;

                    int quot = (next - 1) / n;
                    int rem = (next - 1) % n;

                    int row = n - 1 - quot;

                    int col;

                    if(quot % 2 == 0)
                        col = rem;
                    else
                        col = n - 1 - rem;

                    if(board[row][col] != -1)
                        next = board[row][col];

                    if(!visited[next]) {

                        visited[next] = true;
                        q.push(next);
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};