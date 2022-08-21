class Solution {
    public int trailingZeroes(int n) {
        int ans = 0;
        long tmp = n;
        for (long i =5; i <= tmp; i *= 5) {
            ans += n / i;
        }
        return ans;
    }
}
