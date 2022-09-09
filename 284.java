// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html

import java.util.Iterator;

class PeekingIterator implements Iterator<Integer> {
    private Integer peek;
    Iterator<Integer> iterator;
    boolean hasNext;
    public PeekingIterator(Iterator<Integer> it) {
        // initialize any member here.
        if (it.hasNext()) {
            peek = it.next();
            hasNext = true;
        } else {
            peek = 0;
            hasNext = false;
        }
        iterator = it;
    }

    // Returns the next element in the iteration without advancing the iterator.
    public Integer peek() {
        return peek;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    @Override
    public Integer next() {
        Integer last = peek;
        if (iterator.hasNext()) {
            peek = iterator.next();
        } else {
            hasNext = false;
        }
        return last;
    }

    @Override
    public boolean hasNext() {
        return hasNext;
    }
}
