class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = 0, ans = 0;
        for (int i : nums) x ^= i;
        for (int i = 0; i < 32; i++) {
            int tmp = 1 << i;
            if ((tmp & k) ^ (tmp & x)) ans ++;
        }
        return ans;
    }
};
