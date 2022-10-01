import java.util.Iterator;
import java.util.List;
import java.util.Stack;

//Problem 341

public class NestedIterator implements Iterator<Integer> {
    private class Frame {
        public List<NestedInteger> nestedList;
        public int index;
        Frame(List<NestedInteger> nestedList, int index) {
            this.nestedList = nestedList;
            this.index = index;
        }
    }
    private Stack<Frame> stack;

    public NestedIterator(List<NestedInteger> nestedList) {
        stack = new Stack<>();
        if (nestedList.size() > 0)
            stack.push(new Frame(nestedList, 0));
    }

    @Override
    public Integer next() {
        Frame frame = stack.peek();
        NestedInteger nestedInteger = frame.nestedList.get(frame.index);
        if (frame.index + 1 < frame.nestedList.size())
            frame.index += 1;
        else
            stack.pop();
        if (nestedInteger.isInteger())
            return nestedInteger.getInteger();
        List<NestedInteger> tmp = nestedInteger.getList();
        if (tmp.size() > 0)
            stack.push(new Frame(tmp, 0));
        return next();
    }

    @Override
    public boolean hasNext() {
        if (stack.isEmpty()) return false;
        Frame frame = stack.peek();
        NestedInteger nestedInteger = frame.nestedList.get(frame.index);
        if (isValid(nestedInteger)) 
            return true;
        else if (frame.index + 1 < frame.nestedList.size())
            frame.index += 1;
        else
            stack.pop();
        return hasNext();
    }

    private boolean isValid(NestedInteger nestedInteger) {
        if (nestedInteger.isInteger()) return true;
        List<NestedInteger> nestedList = nestedInteger.getList();
        for (NestedInteger integer : nestedList) {
            if (isValid(integer)) return true;
        }
        return false;
    }
}
