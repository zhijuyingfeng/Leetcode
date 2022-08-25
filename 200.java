class Solution {
    final char land = '1';
    int ans;
    int m, n;

    private void dfs(int x, int y, boolean first, char[][] grid) {
        final int[] X = {-1, 1, 0, 0};
        final int[] Y = {0, 0, -1, 1};
        if (first) ans += 1;

        grid[x][y] = '0';
        for (int i = 0; i < 4; i++) {
            int nextX = x + X[i];
            int nextY = y + Y[i];
            if (nextX < 0 || nextX >= m) continue;
            if (nextY < 0 || nextY >= n) continue;
            if (land != grid[nextX][nextY]) continue;
            dfs(nextX, nextY, false, grid);

        }
    }
    public int numIslands(char[][] grid) {
        m = grid.length;
        n = grid[0].length;

        for (int i =0; i < m; i++) {
            for (int j =0; j < n; j++) {
                if (land == grid[i][j])
                    dfs(i, j, true, grid);
            }
        }

        return ans;
    }
}
