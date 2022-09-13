import java.util.PriorityQueue;

class Solution {
    static class Node implements Comparable<Node> {
        public int indexOfPrimes;
        public int indexOfArray;
        public int product;
        Node(int ip, int ia, int p) {
            indexOfPrimes = ip;
            indexOfArray = ia;
            product = p;
        }

        @Override
        public int compareTo(Node o) {
            return product - o.product;
        }
    }

    private int product(int a, int b) {
        long p = (long)a * b;
        if (p <= 0x7FFFFFFF) {
            return (int)p;
        }
        return -1;
    }
    public int nthSuperUglyNumber(int n, int[] primes) {
        int cnt = 1, len = primes.length, last = 0;
        int[] array = new int[n];
        PriorityQueue<Node> heap = new PriorityQueue<>();
        array[0] = 1;
        heap.add(new Node(0, 0, primes[0]));
        while (cnt < n) {
            Node tmp = heap.poll();
            if (tmp.indexOfPrimes + 1 < len) {
                int p = product(array[tmp.indexOfArray], primes[tmp.indexOfPrimes + 1]);
                if (p >= 0) heap.add(new Node(tmp.indexOfPrimes + 1, tmp.indexOfArray, p));
            }
            if (tmp.product == last) continue;
            last = tmp.product;
            array[cnt] = tmp.product;
            int p = product(array[cnt], primes[0]);
            if (p >= 0) heap.add(new Node(0, cnt, p));
            cnt += 1;
            
        }
        return array[n - 1];
    }
}
