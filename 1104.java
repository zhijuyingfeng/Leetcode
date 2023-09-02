class Solution {
    public static int log2(int x) {
        int ans = 0;
        while (x >= 2) {
            ans += 1;
            x /= 2;
        }
        return ans;
    }
    public static List<Integer> pathInZigZagTree(int label) {
        LinkedList<Integer> ans = new LinkedList<>();
        while (label > 0) {
            ans.addFirst(label);

            int log = log2(label);
            boolean isZigZag = (log & 1) == 1;
            long sum = (1L << log) + (2L << log) - 1;
            label = (int) (sum - label);
            label >>= 1;
        }
        return ans;
    }
}
