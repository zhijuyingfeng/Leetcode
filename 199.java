class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new LinkedList<>();
        if (root == null) {
            return ans;
        }

        LinkedList<TreeNode> queue = new LinkedList<>();
        queue.addFirst(root);
        queue.addFirst(null);
        TreeNode lastNode = null;
        while (!queue.isEmpty()) {
            TreeNode tmp = queue.pollLast();
            if (tmp != null) {
                lastNode = tmp;
                if (tmp.left != null) {
                    queue.addFirst(tmp.left);
                }
                if (tmp.right != null) {
                    queue.addFirst(tmp.right);
                }
            } else {
                if (!queue.isEmpty()) {
                    queue.addFirst(null);
                }
                ans.add(lastNode.val);
            }
         }

        return ans;
    }
}
