class Solution {
    public int numSquares(int n) {
        int[] dp = new int[10001];
        for (int i = 1; i <= n; i++) {
            dp[i] = i;
            for (int j = 1; j <= 100; j++) {
                if (i - j * j >= 0) {
                    dp[i] = Math.min(dp[i], dp[i - j * j] + 1);
                }
            }
        }
        return dp[n];
    }
}
