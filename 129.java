class Solution {
    private int sum = 0;
    private void helper(TreeNode root, int current) {
        if (root == null) {
            return;
        }
        current *= 10;
        current += root.val;

        if (root.left == null && root.right == null) {
            sum += current;
            return;
        }

        if (root.left != null) {
            helper(root.left, current);
        }
        if (root.right != null) {
            helper(root.right, current);
        }

        current /= 10;
    }

    public int sumNumbers(TreeNode root) {
        helper(root, 0);
        return sum;
    }
}
