class Solution {
    public int integerBreak(int n) {
        int []ans = new int[60];
        ans[1] = 1;
        for (int i = 2; i <= n; i++) {
            int max = 0;
            for (int j = 1; j <= (i >> 1); j++) {
                int tmp = Math.max(Math.max((i - j) * j, ans[i - j] * ans[j]), Math.max(ans[i - j]* j, ans[j] * (i - j)));
                max = Math.max(tmp, max);
            }
            ans[i] = max;
        }
        return ans[n];
    }
}
