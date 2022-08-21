class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int length = numbers.length;
        int x = 0, y = length - 1;
        while (x < y) {
            int sum = numbers[x] + numbers[y];
            if (sum > target) {
                y--;
            } else if (sum < target) {
                x++;
            } else {
                int[] ans = {x+ 1, y + 1};
                return ans;
            }
            
        }
        int[] ans = {};
        return ans;
    }
}
