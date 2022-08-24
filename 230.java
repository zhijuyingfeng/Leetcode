class Solution {
    private void traverse(TreeNode root, int[] buckets) {
        if (root != null) {
            buckets[root.val]++;
        }
        if (root.left != null) {
            traverse(root.left, buckets);
        }
        if (root.right != null) {
            traverse(root.right, buckets);
        }
    }

    public int kthSmallest(TreeNode root, int k) {
        final int N = 10001;
        int[] buckets = new int[N];
        traverse(root, buckets);
        for (int i = 0; i < N; i++) {
            if (buckets[i] > 0) {
                k -= buckets[i];
                if (k <= 0) {
                    return i;
                }
            }
        }

        return 0;
    }
}
