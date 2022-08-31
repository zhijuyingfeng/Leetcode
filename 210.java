class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int ans[] = new int[numCourses];
        int[] inDegrees = new int[numCourses];
        LinkedList<Integer>[] lists = new LinkedList[numCourses];
        for (int i = 0; i < numCourses; i++) lists[i] = new LinkedList<>();
        for (int[] prerequisity : prerequisites) {
            inDegrees[prerequisity[0]] += 1;
            lists[prerequisity[1]].add(prerequisity[0]);
        }
        LinkedList<Integer>queue = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (inDegrees[i] == 0) {
                queue.addFirst(i);
            }
        }
        int cnt = 0;
        while (!queue.isEmpty()) {
            int course = queue.pollLast();
            ans[cnt++] = course;
            LinkedList<Integer> list = lists[course];
            for (Integer c : list) {
                inDegrees[c] -= 1;
                if (inDegrees[c] == 0) {
                    queue.addFirst(c);
                }
            }
        }
        if (cnt == numCourses) return ans;
        int[] empty = {};
        return empty;
    }
}
