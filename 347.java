import java.util.*;

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        List<Map.Entry<Integer, Integer>> counts = new LinkedList<>(map.entrySet());
        Collections.sort(counts, new Comparator<Map.Entry<Integer, Integer>>(){
            @Override
            public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
                return o1.getValue() - o2.getValue();
            }
        });
        int[] ans = new int[k];
        int cnt = 0;
        for (Map.Entry<Integer, Integer> pair: counts) {
            if (cnt >= k) break;
            ans[cnt] = pair.getKey();
            cnt += 1;
        }
        return ans;
    }
}
