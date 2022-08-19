class Solution {
    private  void rotate(TreeNode root) {
        if (root == null) {
            return;
        }

        if (root.left != null) {
            rotate(root.left);
        }

        if (root.right != null) {
            rotate(root.right);
        }

        if (root.left != null) {
            TreeNode leftMax = findMax(root.left);
            leftMax.right = root.right;
            root.right = root.left;
            root.left = null;
        }
    }

    private TreeNode findMax(TreeNode root) {
        if (root == null) {
            return null;
        }

        if (root.right != null) {
            return findMax(root.right);
        } else if (root.left != null) {
            return findMax(root.left);
        } else {
            return root;
        }
    }

    public void flatten(TreeNode root) {
        rotate(root);
    }
}
