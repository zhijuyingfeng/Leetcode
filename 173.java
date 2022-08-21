class BSTIterator {
    private LinkedList<TreeNode> stack;

    private void push(TreeNode root) {
        while (root != null) {
            stack.push(root);
            root = root.left;
        }
    }

    public BSTIterator(TreeNode root) {
        stack = new LinkedList<>();
        push(root);
    }

    public int next() {
        TreeNode node = stack.pop();
        push(node.right);
        return node.val;
    }

    public boolean hasNext() {
        return !stack.isEmpty();
    }
}
