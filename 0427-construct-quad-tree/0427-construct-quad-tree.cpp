class Solution {
public:

    Node* solve(vector<vector<int>>& grid,
                int r,
                int c,
                int size) {

        // 1. Assume all values are same
        bool same = true;

        // First element as reference value
        int value = grid[r][c];

        // 2. Check entire square
        for (int i = r; i < r + size; i++) {
            for (int j = c; j < c + size; j++) {

                if (grid[i][j] != value) {
                    same = false;
                    break;
                }
            }

            if (!same)
                break;
        }

        // 3. If all values are same
        if (same) {
            return new Node(value, true);
        }

        // 4. Otherwise divide into 4 parts
        int half = size / 2;

        Node* topLeft =
            solve(grid, r, c, half);

        Node* topRight =
            solve(grid, r, c + half, half);

        Node* bottomLeft =
            solve(grid, r + half, c, half);

        Node* bottomRight =
            solve(grid, r + half, c + half, half);

        // 5. Current node is an internal node
        return new Node(
            true,
            false,
            topLeft,
            topRight,
            bottomLeft,
            bottomRight
        );
    }

    Node* construct(vector<vector<int>>& grid) {

        int n = grid.size();

        return solve(grid, 0, 0, n);
    }
};