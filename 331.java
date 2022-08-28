class Node {
    public String val;
    public int flag;
    Node(String v, int f) {
        val = v;
        flag = f;
    }
}

class Solution {
    public boolean isValidSerialization(String preorder) {
        String[] parts = preorder.split(",");
        int num = parts.length;
        if (num == 0) return false;
        
        LinkedList<Node> stack = new LinkedList<>();
        for (int i = 0; i < num; i++) {
            if (parts[i].equals("#")) {
                if (stack.isEmpty()) return num == 1;
                if (stack.peek().flag == 2) return false;
                stack.peek().flag += 1;
                while (!stack.isEmpty() && stack.peek().flag == 2) {
                    stack.pop();
                    if (!stack.isEmpty()) {
                        stack.peek().flag += 1;
                    }
                }
                if (stack.isEmpty() && i != num - 1) return false;
            } else {
                stack.push(new Node(parts[i], 0));
            }
        }

        return stack.isEmpty();
    }
}
