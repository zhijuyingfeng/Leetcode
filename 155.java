class Frame {
    int val;
    int min;
    Frame() {
        val = Integer.MAX_VALUE;
        min = Integer.MAX_VALUE;
    }
    Frame(int v, int m) {
        val = v;
        min = m;
    }
}
class MinStack {
    private LinkedList<Frame> stack;
    public MinStack() {
        stack = new LinkedList<>();
        stack.push(new Frame());
    }

    public void push(int val) {
        int lastMin = stack.peek().min;
        stack.push(new Frame(val, Integer.min(val, lastMin)));
    }

    public void pop() {
        stack.pop();
    }

    public int top() {
        return stack.peek().val;
    }

    public int getMin() {
        return stack.peek().min;
    }
}
