class Solution {
    public Node connect(Node root) {
        if (root == null) {
            return null;
        }
        LinkedList<Node> queue = new LinkedList<>();
        queue.addFirst(root);
        queue.addFirst(null);
        Node last = null;
        while(!queue.isEmpty()) {
            Node current = queue.pollLast();
            if (last != null) {
                last.next = current;
            }
            last = current;
            if (current != null) {
                if (current.left != null) {
                    queue.addFirst(current.left);
                }
                if (current.right != null) {
                    queue.addFirst(current.right);
                }
            } else if (!queue.isEmpty()) {
                queue.addFirst(null);
            }
        }
        return root;
    }
}
