class Solution {
    public int evalRPN(String[] tokens) {
        LinkedList<Integer> stack = new LinkedList<>();
        int ans = 0;
        for (String token : tokens) {
            if (token.equals("*")) {
                int op2 = stack.pop();
                int op1 = stack.pop();
                ans = op1 * op2;
                stack.push(ans);
            } else if (token.equals("/")) {
                int op2 = stack.pop();
                int op1 = stack.pop();
                ans = op1 / op2;
                stack.push(ans);
            } else if (token.equals("+")) {
                int op2 = stack.pop();
                int op1 = stack.pop();
                ans = op1 + op2;
                stack.push(ans);
            } else if (token.equals("-")) {
                int op2 = stack.pop();
                int op1 = stack.pop();
                ans = op1 - op2;
                stack.push(ans);
            } else {
                stack.push(Integer.parseInt(token));
            }
        }

        return stack.pop();
    }
}
